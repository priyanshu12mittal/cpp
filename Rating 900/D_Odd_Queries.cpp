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
    int n, q;
    cin >> n >> q;
    vi a(n);
    ll total = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        total += a[i];
    }
    vl pfSum(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        pfSum[i + 1] = pfSum[i] + a[i];
    }
    while (q--)
    {
        int l, r;
        ll k;
        cin >> l >> r >> k;
        ll sum = pfSum[r] - pfSum[l - 1];
        ll newTotal = total - sum + k * (r - l + 1);
        cout << ((newTotal % 2 != 0) ? "YES" : "NO") << endl;
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
