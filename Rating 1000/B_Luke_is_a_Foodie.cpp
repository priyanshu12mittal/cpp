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
    ll n, x;
    cin >> n >> x;
    vl v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    ll l = v[0] - x, r = v[0] + x;
    int res = 0;
    for (int i = 1; i < n; i++)
    {
        ll newL = max(l, v[i] - x);
        ll newR = min(r, v[i] + x);
        if (newL <= newR)
        {
            l = newL;
            r = newR;
        }
        else
        {
            res++;
            l = v[i] - x;
            r = v[i] + x;
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