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
    int n, k;
    cin >> n >> k;
    vi a(n * k);
    for (int i = 0; i < n * k; i++)
        cin >> a[i];
    sort(all(a));
    ll ans = 0;
    int d = n / 2;
    int step = d + 1;
    int p = n * k - step;
    for (int i = 0; i < k; i++)
    {
        ans += a[p];
        p -= step;
    }
    cout << ans << '\n';
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
