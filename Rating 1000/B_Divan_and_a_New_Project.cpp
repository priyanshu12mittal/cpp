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
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<pair<ll, int>> freq;
    for (int i = 0; i < n; i++)
    {
        freq.pb({a[i], i + 1});
    }
    sort(freq.begin(), freq.end(), [](auto &p, auto &q)
         { return p.first > q.first; });
    vl ans(n + 1, 0);
    ans[0] = 0;
    ll res = 0;
    int pos = 1;
    for (int i = 0; i < sz(freq); i++)
    {
        if (i % 2 == 0)
        {
            ans[freq[i].second] = pos;
            res += 2ll * pos * freq[i].first;
        }
        else
        {
            ans[freq[i].second] = -pos;
            res += 2ll * pos * freq[i].first;
            pos++;
        }
    }
    cout << res << endl;
    for (int i = 0; i <= n; i++)
    {
        cout << ans[i] << " ";
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