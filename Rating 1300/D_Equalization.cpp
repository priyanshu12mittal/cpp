#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define pii pair<int, int>
#define forn(i, n) for (int i = 0; i < n; i++)
#define pll pair<ll, ll>

void solve()
{
    ll x, y;
    cin >> x >> y;
    if (x == y)
    {
        cout << 0 << "\n";
        return;
    }
    int Lx = 0, Ly = 0;
    {
        long long tmp = x;
        while (tmp > 0)
        {
            Lx++;
            tmp >>= 1;
        }
    }
    {
        long long tmp = y;
        while (tmp > 0)
        {
            Ly++;
            tmp >>= 1;
        }
    }
    int S_bound = Lx + Ly;
    int M = S_bound;

    // Let dp[s][a] represent the minimum cost to achieve a total shift
    // s (that is, A+B=s) with a shift of a applied to x (A = a).
    // Note: since a cannot exceed s, we use a 2D vector with dimensions (S_bound+1) x (S_bound+1).
    const long long INF = 1e19;
    vector<vector<long long>> dp(S_bound + 1, vector<long long>(S_bound + 1, INF));
    dp[0][0] = 0;

    // Process k from 1 to M. For each available k, we have three choices:
    // 1. Do not use k.
    // 2. Use k on x (increasing A by k).
    // 3. Use k on y (increasing B by k).
    for (int k = 1; k <= M; k++)
    {
        vector<vector<long long>> new_dp(S_bound + 1, vector<long long>(S_bound + 1, INF));
        for (int s = 0; s <= S_bound; s++)
        {
            for (int a = 0; a <= s; a++)
            {
                if (dp[s][a] == INF)
                    continue;
                // Option 1: Do nothing with k.
                new_dp[s][a] = min(new_dp[s][a], dp[s][a]);
                // Option 2: Use k on x.
                // New state: s' = s+k, a' = a+k, cost increases by 2^k.
                if (s + k <= S_bound)
                {
                    long long cost2 = dp[s][a] + (1LL << k);
                    new_dp[s + k][a + k] = min(new_dp[s + k][a + k], cost2);
                }
                // Option 3: Use k on y.
                // New state: s' = s+k, a remains the same.
                if (s + k <= S_bound)
                {
                    long long cost3 = dp[s][a] + (1LL << k);
                    new_dp[s + k][a] = min(new_dp[s + k][a], cost3);
                }
            }
        }
        dp = new_dp;
    }

    // Now, iterate over all states to see which ones equalize x and y.
    long long ans = INF;
    for (int s = 0; s <= S_bound; s++)
    {
        for (int a = 0; a <= s; a++)
        {
            if (dp[s][a] == INF)
                continue;
            int A = a;     // Total shift applied to x.
            int B = s - a; // Total shift applied to y.
            // Compute the final values after division by 2^A and 2^B.
            long long x_final = (A < 63 ? x / (1LL << A) : 0);
            long long y_final = (B < 63 ? y / (1LL << B) : 0);
            if (x_final == y_final)
            {
                ans = min(ans, dp[s][a]);
            }
        }
    }

    cout << (ans == INF ? -1 : ans) << "\n";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}