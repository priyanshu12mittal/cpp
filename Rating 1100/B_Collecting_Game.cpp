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
    ll n;
    cin >> n;
    vector<pll> pairs;
    for (ll i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        pairs.push_back({a, i});
    }
    sort(all(pairs));
    vl stop(n, 0);
    ll currSum = pairs[0].first;
    for (ll i = 1; i < n; i++)
    {
        if (pairs[i].first > currSum)
        {
            stop[i - 1] = 1;
        }
        currSum += pairs[i].first;
    }
    ll idx(n - 1);
    for (ll i = n - 1; i >= 0; i--)
    {
        if (stop[i] == 1)
        {
            idx = i;
        }
        stop[i] = idx;
    }
    vl ans(n);
    for (ll i = 0; i < n; i++)
    {
        ans[pairs[i].second] = stop[i];
    }
    for (ll i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";
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