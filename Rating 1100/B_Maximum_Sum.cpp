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
    ll n, k;
    cin >> n >> k;
    vl a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(all(a));
    vl prefix(n + 1, 0);
    for (ll i = 0; i < n; i++)
    {
        prefix[i + 1] = prefix[i] + a[i];
    }
    ll ans = 0;
    for (ll i = 0; i <= k; i++)
    {
        ll y = k - i;
        if (2 * i + y > n)
        {
            continue;
        }
        ll right = n - y;
        ll left = 2 * i;
        ans = max(ans, prefix[right] - prefix[left]);
    }
    cout << ans << "\n";
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