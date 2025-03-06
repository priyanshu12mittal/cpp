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
const ll MOD = 1000000007;

void solve()
{
    int n;
    cin >> n;
    vl a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    sort(all(a));
    sort(all(b));
    ll res = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        int pos = upper_bound(all(a), b[i]) - a.begin();
        ll count = n - pos;
        ll valid = count - ((n - 1) - i);

        if (valid <= 0)
        {
            cout << 0 << "\n";
            return;
        }

        res = (res * valid) % MOD;
    }
    cout << res << "\n";
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