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
    ll k, x;
    cin >> k >> x;
    ll total = k * k;
    if (total <= x)
    {
        cout << 2 * k - 1 << endl;
        return;
    }
    ll sum = (k * (k + 1)) / 2;
    if (x <= sum)
    {
        ll lo = 1, hi = k;
        while (lo < hi)
        {
            ll mid = lo + (hi - lo) / 2;
            ll curr = (mid * (mid + 1)) / 2;
            if (curr >= x)
            {
                hi = mid;
            }
            else
            {
                lo = mid + 1;
            }
        }
        cout << lo << endl;
    }
    else
    {
        ll downSum = x - sum;
        ll lo = 1, hi = k - 1;
        while (lo < hi)
        {
            ll mid = lo + (hi - lo) / 2;
            ll curr = mid * k - (mid * (mid + 1)) / 2;
            if (curr >= downSum)
            {
                hi = mid;
            }
            else
            {
                lo = mid + 1;
            }
        }
        cout << k + lo << endl;
    }
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