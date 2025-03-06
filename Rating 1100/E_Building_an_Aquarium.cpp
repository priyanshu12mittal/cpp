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
    vl a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll low = 0, high = *max_element(all(a)) + x;
    while (low < high)
    {
        ll mid = (low + high + 1) / 2;
        ll cnt = 0;
        for (ll i = 0; i < n; i++)
        {
            cnt += max(0LL, mid - a[i]);
        }
        if (cnt <= x)
        {
            low = mid;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << low << "\n";
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