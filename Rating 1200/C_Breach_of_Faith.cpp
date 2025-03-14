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
    cin >> n;
    int total = 2 * n;
    vl b(total);
    for (int i = 0; i < total; i++)
    {
        cin >> b[i];
    }
    sort(all(b));
    ll a1 = b.back();
    vl remaining(all(b) - 1);
    vl first, second;
    for (int i = 0; i < (n - 1); i++)
    {
        first.pb(remaining[i]);
    }
    for (int i = n - 1; i < (int)remaining.size(); i++)
    {
        second.pb(remaining[i]);
    }
    ll sum2 = 0, sum1 = 0;
    for (ll num : second)
        sum2 += num;
    for (ll num : first)
        sum1 += num;
    ll x = a1 + sum2 - sum1;
    vl a(2 * n + 1);
    a[0] = a1;
    a[1] = x;
    int idx = 2;
    for (int i = 0; i < n; i++)
    {
        a[idx++] = second[i];
        if (i < n - 1)
        {
            a[idx++] = first[i];
        }
    }
    for (ll num : a)
    {
        cout << num << " ";
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