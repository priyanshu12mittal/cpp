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
    ll k, x;
    cin >> n >> k >> x;
    vl a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(all(a));
    vl gaps;
    for (int i = 1; i < n; i++)
    {
        ll diff = a[i] - a[i - 1];
        if (diff > x)
        {
            ll needed = (diff - 1) / x;
            gaps.pb(needed);
        }
    }
    int res = sz(gaps) + 1;
    sort(all(gaps));
    for (ll need : gaps)
    {
        if (k >= need)
        {
            k -= need;
            res--;
        }
        else
        {
            break;
        }
    }
    cout << res << "\n";
}
int main()
{
    // int t;
    // cin >> t;
    // while (t--)
    // {
    solve();
    // }
    return 0;
}