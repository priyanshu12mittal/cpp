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
    ll n, k, b, s;
    cin >> n >> k >> b >> s;
    if (s > k * b + n * (k - 1) || s < k * b)
    {
        cout << -1 << endl;
        return;
    }
    vl a(n, 0);
    a[0] = k * b;
    ll extra = s - k * b;
    for (int i = 0; i < n && extra > 0; i++)
    {
        ll add = min(extra, k - 1ll);
        a[i] += add;
        extra -= add;
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
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