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
    cin >> n;
    if (n % 2 == 0)
    {
        cout << n / 2 << " " << n / 2 << "\n";
    }
    else
    {
        ll divisor = -1;
        for (ll i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                divisor = i;
                break;
            }
        }
        if (divisor == -1)
        {
            cout << 1 << " " << n - 1 << "\n";
        }
        else
        {
            ll a = n / divisor;
            ll b = n - a;
            cout << a << " " << b << "\n";
        }
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