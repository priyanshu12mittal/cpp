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
    ll n;
    int m;
    cin >> n >> m;
    vl a(m);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    sort(all(a));
    int y = 0;
    int saved = 0;
    vl segments;
    segments.pb(n - a[m - 1] + a[0] - 1);
    for (int i = 1; i < m; i++)
    {
        segments.pb(a[i] - a[i - 1] - 1);
    }
    sort(segments.rbegin(), segments.rend());
    for (int i = 0; i < sz(segments); i++)
    {
        ll x = segments[i] - 2 * y;
        if (x <= 0)
        {
            continue;
        }
        if (x == 1 || x == 2)
        {
            saved++;
            y++;
        }
        else
        {
            saved += x - 1;
            y += 2;
        }
    }
    cout << n - saved << "\n";
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