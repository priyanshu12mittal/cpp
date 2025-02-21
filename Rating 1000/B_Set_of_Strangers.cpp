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
#define pll pair<ll, ll>

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    int maxColor = n * m;
    vector<bool> seen(maxColor + 1, false);
    vector<bool> nonInd(maxColor + 1, false);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            seen[grid[i][j]] = true;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int cur = grid[i][j];
            if (j + 1 < m && grid[i][j + 1] == cur)
                nonInd[cur] = true;
            if (i + 1 < n && grid[i + 1][j] == cur)
                nonInd[cur] = true;
        }
    }
    int k1 = 0, k2 = 0;
    for (int c = 1; c <= maxColor; c++)
    {
        if (seen[c])
        {
            if (nonInd[c])
                k2++;
            else
                k1++;
        }
    }
    int totalCost = k1 + 2 * k2;
    int saving = (k2 > 0 ? 2 : 1);
    int answer = totalCost - saving;

    cout << answer << "\n";
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
