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
    ll n, c;
    cin >> n >> c;
    vl a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll low = 1, high = 1e9;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        __int128 total = 0;
        for (ll i = 0; i < n; i++)
        {
            ll side = a[i] + 2 * mid;
            total += (__int128)side * side;
        }
        if (total == (__int128)c)
        {
            cout << mid << "\n";
            return;
        }
        else if (total < (__int128)c)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
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
