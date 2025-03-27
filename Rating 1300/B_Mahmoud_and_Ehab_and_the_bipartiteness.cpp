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

void dfs(int node, int color, const vvi &adj, vi &vis)
{
    vis[node] = color;
    for (int neigh : adj[node])
    {
        if (vis[neigh] == -1)
        {
            dfs(neigh, 1 - color, adj, vis);
        }
    }
}

void solve()
{
    int n;
    cin >> n;

    vvi adj(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vi vis(n + 1, -1);
    dfs(1, 0, adj, vis);
    ll count0 = 0, count1 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            count0++;
        }
        else
            count1++;
    }
    ll res = count0 * count1 - (n - 1);
    cout << res << endl;
}
int main()
{
    // int t;
    // cin >> t;
    // while (t--)
    // {
    solve();
    // }
    // return 0;
}