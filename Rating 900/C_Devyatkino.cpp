#include <bits/stdc++.h>
using namespace std;

inline int encodeState(int carry, int last, bool flag)
{
    return (carry << 5) | (last << 1) | (flag ? 1 : 0);
}

inline void decodeState(int st, int &carry, int &last, bool &flag)
{
    flag = (st & 1) != 0;
    last = (st >> 1) & 0xF;
    carry = st >> 5;
}

bool canAchieve(const vector<int> &digits, int L, int r)
{
    vector<int> currStates, nextStates;
    currStates.reserve(20);
    nextStates.reserve(20);
    int d0 = digits[0];
    int tot = d0 + 9 * r;
    int newDigit = tot % 10;
    int newCarry = tot / 10;
    bool newFlag = (newDigit == 7);
    currStates.push_back(encodeState(newCarry, r, newFlag));
    for (int pos = 1; pos < L; pos++)
    {
        nextStates.clear();
        unordered_set<int> seen;
        seen.reserve(100);
        int d = digits[pos];
        for (int st : currStates)
        {
            int carry, last;
            bool flag;
            decodeState(st, carry, last, flag);
            for (int c = 0; c <= last; c++)
            {
                int tot = d + 9 * c + carry;
                int nd = tot % 10;
                int nc = tot / 10;
                bool nf = flag || (nd == 7);
                int newState = encodeState(nc, c, nf);
                if (seen.find(newState) == seen.end())
                {
                    seen.insert(newState);
                    nextStates.push_back(newState);
                }
            }
        }
        currStates.swap(nextStates);
        if (currStates.empty())
            break;
    }
    for (int st : currStates)
    {
        int carry, last;
        bool flag;
        decodeState(st, carry, last, flag);
        if (flag)
            return true;
        int tmp = carry;
        while (tmp > 0)
        {
            if (tmp % 10 == 7)
                return true;
            tmp /= 10;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s = to_string(n);
        bool has7 = false;
        for (char c : s)
        {
            if (c == '7')
            {
                has7 = true;
                break;
            }
        }
        if (has7)
        {
            cout << 0 << "\n";
            continue;
        }
        vector<int> digits;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            digits.push_back(s[i] - '0');
        }
        int origLen = digits.size();
        int L = origLen + 3;
        digits.resize(L, 0);
        int ans = -1;
        for (int r = 1; r <= 9; r++)
        {
            if (canAchieve(digits, L, r))
            {
                ans = r;
                break;
            }
        }
        if (ans == -1)
            ans = 9;
        cout << ans << "\n";
    }
    return 0;
}
