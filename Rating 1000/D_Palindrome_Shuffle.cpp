#include <bits/stdc++.h>
using namespace std;

// We'll represent frequency vectors as an array of 26 ints.
typedef array<int, 26> Freq;

// Utility: add two frequency vectors.
Freq addFreq(const Freq &a, const Freq &b)
{
    Freq res;
    for (int i = 0; i < 26; i++)
    {
        res[i] = a[i] + b[i];
    }
    return res;
}

// Utility: subtract vector b from a.
Freq subFreq(const Freq &a, const Freq &b)
{
    Freq res;
    for (int i = 0; i < 26; i++)
    {
        res[i] = a[i] - b[i];
    }
    return res;
}

// Check condition: for each letter, supply >= demand and (supply-demand) is even.
bool checkFreq(const Freq &supply, const Freq &demand)
{
    for (int i = 0; i < 26; i++)
    {
        int diff = supply[i] - demand[i];
        if (diff < 0 || (diff & 1))
            return false;
    }
    return true;
}

// Given a prefix frequency array (prefix[0] = 0, prefix[i+1] = prefix[i] + letter at index i),
// return the frequency vector for the interval [L, R] (inclusive).
Freq getFreq(const vector<Freq> &prefix, int L, int R)
{
    Freq res;
    for (int c = 0; c < 26; c++)
    {
        res[c] = prefix[R + 1][c] - prefix[L][c];
    }
    return res;
}

// Build a prefix frequency array for s[start...end] (inclusive)
vector<Freq> buildPrefix(const string &s, int start, int end)
{
    int len = end - start + 1;
    vector<Freq> pref(len + 1);
    for (int i = 0; i < 26; i++)
        pref[0][i] = 0;
    for (int i = 0; i < len; i++)
    {
        pref[i + 1] = pref[i];
        pref[i + 1][s[start + i] - 'a']++;
    }
    return pref;
}

// Main
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        // n is even.
        int m = n / 2;

        // First, check if s is already a palindrome.
        bool already = true;
        for (int i = 0; i < m; i++)
        {
            if (s[i] != s[n - 1 - i])
            {
                already = false;
                break;
            }
        }
        if (already)
        {
            cout << 0 << "\n";
            continue;
        }

        // Split the string into left half and right half.
        string leftStr = s.substr(0, m);
        string rightStr = s.substr(m, m);

        // Build prefix frequency arrays for left half, right half, and for the full string.
        vector<Freq> leftPref = buildPrefix(s, 0, m - 1);
        vector<Freq> rightPref = buildPrefix(s, m, n - 1);
        vector<Freq> globalPref = buildPrefix(s, 0, n - 1);

        // Build diff array for left half: for i in [0, m-1],
        // diff = 1 if s[i] != s[n-1-i] (i.e. the pair (i, n-1-i) is mismatched)
        vector<int> leftDiff(m, 0);
        for (int i = 0; i < m; i++)
        {
            leftDiff[i] = (s[i] != s[n - 1 - i]);
        }
        // Build a prefix sum for leftDiff.
        vector<int> leftDiffPref(m + 1, 0);
        for (int i = 0; i < m; i++)
        {
            leftDiffPref[i + 1] = leftDiffPref[i] + leftDiff[i];
        }

        // Similarly, for right half: for j in [0, m-1] (rightStr[j] = s[m+j]),
        // partner is s[m-1-j].
        vector<int> rightDiff(m, 0);
        for (int j = 0; j < m; j++)
        {
            rightDiff[j] = (s[m + j] != s[m - 1 - j]);
        }
        vector<int> rightDiffPref(m + 1, 0);
        for (int j = 0; j < m; j++)
        {
            rightDiffPref[j + 1] = rightDiffPref[j] + rightDiff[j];
        }

        const int INF = 1e9;

        // ===========================
        // Candidate A: T lies entirely in the left half.
        // In this case T = [i,j] with 0<=i<=j < m.
        // For every index k in T, the "demand" is the letter from its partner: s[n-1-k].
        // Also, every pair that is fixed (i.e. not touched) must already match.
        int bestA = INF;
        int L0 = INF, R0 = -1; // Let L0 = first index in left half with diff==1, R0 = last such index.
        for (int i = 0; i < m; i++)
        {
            if (leftDiff[i] == 1)
            {
                L0 = min(L0, i);
                R0 = max(R0, i);
            }
        }
        if (L0 == INF)
        {
            bestA = 0;
        }
        else
        {
            // Two–pointer scan: for i from 0 to L0 and j from max(R0,i) upward.
            int j = R0;
            for (int i = 0; i <= L0; i++)
            {
                if (leftDiffPref[i] != 0)
                    continue; // positions before i must be fixed.
                if (j < R0)
                    j = R0;
                while (j < m)
                {
                    // Check that indices after j are fixed.
                    if ((leftDiffPref[m] - leftDiffPref[j + 1]) != 0)
                    {
                        j++;
                        continue;
                    }
                    // Supply from T = [i,j] in left half.
                    Freq supply = getFreq(leftPref, i, j);
                    // Demand comes from the partners of positions i..j.
                    // Those are indices: for k in [i,j], partner = n-1-k.
                    // They form a contiguous block in the right half:
                    // [ (n-1 - j), (n-1 - i) ] = [2*m -1 - j, 2*m -1 - i ].
                    // In our rightPref (0-indexed for rightStr) subtract m:
                    int rdL = m - 1 - j; // lower bound in right half prefix index
                    int rdR = m - 1 - i; // upper bound in right half prefix index
                    if (rdL < 0)
                        rdL = 0;
                    if (rdR >= m)
                        rdR = m - 1;
                    Freq demand = getFreq(rightPref, rdL, rdR);
                    if (checkFreq(supply, demand))
                    {
                        bestA = min(bestA, j - i + 1);
                        break; // for this i we found a valid interval
                    }
                    else
                    {
                        j++;
                    }
                }
                if (j >= m)
                    break;
            }
        }

        // ===========================
        // Candidate B: T lies entirely in the right half.
        // (This case is symmetric to Candidate A.)
        int bestB = INF;
        int L1 = INF, R1 = -1; // over right half (0-indexed relative to rightStr)
        for (int j = 0; j < m; j++)
        {
            if (rightDiff[j] == 1)
            {
                L1 = min(L1, j);
                R1 = max(R1, j);
            }
        }
        if (L1 == INF)
        {
            bestB = 0;
        }
        else
        {
            int rj = R1;
            for (int i = 0; i <= L1; i++)
            {
                if (rightDiffPref[i] != 0)
                    continue;
                if (rj < R1)
                    rj = R1;
                while (rj < m)
                {
                    if ((rightDiffPref[m] - rightDiffPref[rj + 1]) != 0)
                    {
                        rj++;
                        continue;
                    }
                    // T in right half = [i, rj]
                    Freq supply = getFreq(rightPref, i, rj);
                    // Its corresponding partners (in left half) are:
                    // for x in [i, rj] in right half, partner = m -1 - x.
                    // So demand is frequency from leftPref over [m-1-rj, m-1-i].
                    int ldL = m - 1 - rj;
                    int ldR = m - 1 - i;
                    if (ldL < 0)
                        ldL = 0;
                    if (ldR >= m)
                        ldR = m - 1;
                    Freq demand = getFreq(leftPref, ldL, ldR);
                    if (checkFreq(supply, demand))
                    {
                        bestB = min(bestB, rj - i + 1);
                        break;
                    }
                    else
                    {
                        rj++;
                    }
                }
                if (rj >= m)
                    break;
            }
        }

        // ===========================
        // Candidate C: T spans both halves.
        // Here T = [L, R] with L in [0, m-1] and R in [m, 2*m-1].
        // (Outside T, every fixed pair must already match.)
        // In addition we compute two “demand” parts:
        //   - For indices i in [L, min(m, 2*m-R)) that are in T (left half) with fixed partner (outside T)
        //   - For indices in [max(0, 2*m-1-R), L) (left half) whose partner in right half is inside T.
        auto checkSpan = [&](int L, int R) -> bool
        {
            // L in [0, m-1], R in [m, 2*m-1].
            // Fully fixed condition: for every i < L that is fixed (and whose partner is not in T),
            // we require s[i]==s[n-1-i]. It is enough to check for i in [0, t) where t = min(L, 2*m - R).
            int t = min(L, 2 * m - R);
            if (t > 0 && leftDiffPref[t] != 0)
                return false;

            // Demand from half–covered pairs.
            // Set A: indices in [L, X) where X = min(m, 2*m - R).
            int X = min(m, 2 * m - R);
            Freq demandA;
            for (int c = 0; c < 26; c++)
                demandA[c] = 0;
            if (X > L)
            {
                // For i in [L, X), partner = 2*m-1-i.
                // Their set forms an interval in right half:
                // from index (2*m-1 - L) down to (2*m - (X))
                int rLow = (2 * m - X);      // smallest actual index in s (in right half)
                int rHigh = (2 * m - 1 - L); // largest actual index in s (in right half)
                int rpL = rLow - m;          // convert to rightPref index
                int rpR = rHigh - m;
                if (rpL < 0)
                    rpL = 0;
                if (rpR >= m)
                    rpR = m - 1;
                demandA = getFreq(rightPref, rpL, rpR);
            }
            // Set B: indices in [Y, L) where Y = max(0, 2*m - 1 - R).
            int Y = max(0, 2 * m - 1 - R);
            Freq demandB;
            for (int c = 0; c < 26; c++)
                demandB[c] = 0;
            if (L > Y)
            {
                demandB = getFreq(leftPref, Y, L - 1);
            }

            Freq totalDemand;
            for (int c = 0; c < 26; c++)
            {
                totalDemand[c] = demandA[c] + demandB[c];
            }

            // Supply: T = [L, R] in the full string.
            Freq supply = getFreq(globalPref, L, R);

            return checkFreq(supply, totalDemand);
        };

        // We binary search on length k = R - L + 1 for spanning intervals.
        int bestC = INF;
        int lo_k = 1, hi_k = n;
        int ansC = INF;
        while (lo_k <= hi_k)
        {
            int mid = (lo_k + hi_k) / 2;
            bool possible = false;
            // T = [L, R] with R = L + mid - 1.
            // To span both halves we need L < m and R >= m.
            // Hence L must be in [max(0, m - mid + 1), min(m-1, 2*m - mid)].
            int Lmin = max(0, m - mid + 1);
            int Lmax = min(m - 1, 2 * m - mid);
            for (int L = Lmin; L <= Lmax; L++)
            {
                int R = L + mid - 1;
                if (R < m)
                    continue;
                if (R >= n)
                    continue;
                if (checkSpan(L, R))
                {
                    possible = true;
                    break;
                }
            }
            if (possible)
            {
                ansC = mid;
                hi_k = mid - 1;
            }
            else
            {
                lo_k = mid + 1;
            }
        }
        bestC = ansC;

        int best = INF;
        best = min(best, bestA);
        best = min(best, bestB);
        best = min(best, bestC);
        if (best == INF)
            best = n;
        cout << best << "\n";
    }
    return 0;
}
