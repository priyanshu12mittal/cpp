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

struct arrInfo
{
    ll total;
    ll internal;
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<arrInfo> arr(n);
    for (int i = 0; i < n; i++)
    {
        long long prefix = 0, internal = 0, total = 0;
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            prefix += x;
            internal += prefix;
            total += x;
        }
        arr[i] = {total, internal};
    }
    sort(arr.begin(), arr.end(), [](const arrInfo &a, const arrInfo &b)
         { return a.total > b.total; });
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += arr[i].internal;
    }
    for (int i = 0; i < n; i++)
    {
        ans += (long long)m * (n - 1 - i) * arr[i].total;
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
