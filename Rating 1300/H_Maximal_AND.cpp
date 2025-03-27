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
    ll k;
    cin >> n >> k;
    vl a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll res = 0;
    for (int j = 30; j >= 0; j--)
    {
        ll missing = 0;
        for (int i = 0; i < n; i++)
        {
            if ((a[i] & 1LL << j) == 0)
            {
                missing++;
            }
        }
        if (missing <= k)
        {
            res |= (1LL << j);
            k -= missing;
            for (int i = 0; i < n; i++)
            {
                if ((a[i] & 1LL << j) == 0)
                {
                    a[i] |= (1LL << j);
                }
            }
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