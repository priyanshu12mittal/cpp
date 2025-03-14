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
    int n, m;
    cin >> n >> m;
    vvl a(n, vl(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    ll total = 0;
    for (int j = 0; j < m; j++)
    {
        vl col(n);
        for (int i = 0; i < n; i++)
        {
            col[i] = a[i][j];
        }
        sort(all(col));
        for (int i = 0; i < n; i++)
        {
            total += col[i] * (2 * i - n + 1);
        }
    }
    cout << total << "\n";
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