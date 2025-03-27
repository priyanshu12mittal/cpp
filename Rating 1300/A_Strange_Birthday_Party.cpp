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
    vl k(n);
    vl c(m);
    for (int i = 0; i < n; i++)
    {
        cin >> k[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> c[i];
    }
    sort(k.rbegin(), k.rend());
    int i = 0;
    ll total = 0;
    for (int j = 0; j < n; j++)
    {
        if (i + 1 <= k[j])
        {
            total += c[i];
            i++;
        }
        else
        {
            total += c[k[j] - 1];
        }
    }
    cout << total << endl;
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