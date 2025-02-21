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
    ll n, k, q;
    cin >> n >> k >> q;
    vl a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll count = 0;
    ll curr = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= q)
        {
            curr++;
        }
        else
        {
            if (curr >= k)
            {
                ll x = curr - k + 1;
                count += x * (x + 1ll) / 2;
            }
            curr = 0;
        }
    }
    if (curr >= k)
    {
        ll x = curr - k + 1;
        count += x * (x + 1) / 2;
    }

    cout << count << endl;
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