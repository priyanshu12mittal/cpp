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
    vector<pair<ll, int>> b;
    while (n--)
    {
        int k;
        cin >> k;
        ll curr = 0;
        for (int i = 0; i < k; i++)
        {
            ll x;
            cin >> x;
            curr = max(curr, x - i);
        }
        b.pb({curr, k});
    }
    sort(all(b));
    ll res = 0, current = 0;
    for (auto &bi : b)
    {
        ll req = bi.first;
        int k = bi.second;
        if (current <= req)
        {
            res += (req - current + 1);
            current = req + 1;
        }
        current += k;
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