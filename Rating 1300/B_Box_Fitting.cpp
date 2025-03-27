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
    ll W;
    cin >> n >> W;
    vl freq(32, 0);
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        int p = 0;
        while ((1LL << p) < x)
        {
            p++;
        }
        freq[p]++;
    }
    int res = 0;
    while (n)
    {
        res++;
        ll rem = W;
        for (int p = 31; p >= 0; p--)
        {
            ll w = (1LL << p);
            ll canFit = rem / w;
            ll used = min(freq[p], canFit);
            freq[p] -= used;
            n -= used;
            rem -= used * w;
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