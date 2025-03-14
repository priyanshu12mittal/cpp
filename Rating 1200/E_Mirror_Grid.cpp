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
    int n;
    cin >> n;
    vvi grid(n, vi(n));
    for (int i = 0; i < n; i++)
    {
        string row;
        cin >> row;
        for (int j = 0; j < n; j++)
        {
            grid[i][j] = row[j] - '0';
        }
    }
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    ll res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!vis[i][j])
            {
                vector<pii> v;
                int a = i, b = j;
                do
                {
                    v.push_back({a, b});
                    vis[a][b] = true;
                    int na = b, nb = n - 1 - a;
                    a = na;
                    b = nb;
                } while (a != i || b != j);
                int sum = 0;
                for (int k = 0; k < v.size(); k++)
                {
                    sum += grid[v[k].first][v[k].second];
                }
                res += min(sz(v) - sum, sum);
            }
        }
    }
    cout << res << "\n";
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