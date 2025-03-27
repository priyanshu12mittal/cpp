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

ll maxDesks(ll m, ll l)
{
    return m - (m / (l + 1));
}

void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    ll lo = 1, hi = m;
    ll res = m;
    while (lo <= hi)
    {
        ll mid = lo + (hi - lo) / 2;
        if (n * maxDesks(m, mid) >= k)
        {
            res = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    cout << res << endl;
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
