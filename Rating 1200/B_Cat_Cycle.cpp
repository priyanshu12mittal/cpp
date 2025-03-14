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
    ll n, k;
    cin >> n >> k;
    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }
    ll pos;
    if (n % 2 == 0)
    {
        pos = ((k - 1) % n) + 1;
    }
    else
    {
        ll f = n / 2;
        pos = (((k - 1) + ((k - 1) / f)) % n) + 1;
    }
    cout << pos << endl;
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