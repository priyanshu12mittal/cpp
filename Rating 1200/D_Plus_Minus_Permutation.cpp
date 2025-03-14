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
    ll n, x, y;
    cin >> n >> x >> y;
    ll a = n / x;
    ll b = n / y;
    ll both = n / lcm(x, y);
    ll validX = a - both;
    ll validY = b - both;
    ll sum1 = (validX * (2 * n - validX + 1)) / 2;
    ll sum2 = (validY * (validY + 1)) / 2;
    cout << sum1 - sum2 << "\n";
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