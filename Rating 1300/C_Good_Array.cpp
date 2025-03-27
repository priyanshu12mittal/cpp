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
    vi a(n);
    unordered_map<int, int> mp;
    ll total = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
        total += a[i];
    }
    vi res;
    for (int i = 0; i < n; i++)
    {
        ll curr = total - a[i];
        int x = curr / 2;
        if (2 * x != curr)
        {
            continue;
        }
        mp[a[i]]--;
        if (mp.find(x) != mp.end() && mp[x] != 0)
        {
            res.pb(i + 1);
        }
        mp[a[i]]++;
    }
    cout << sz(res) << endl;
    for (auto &num : res)
    {
        cout << num << " ";
    }
    cout << endl;
}
int main()
{
    // int t;
    // cin >> t;
    // while (t--)
    // {
    solve();
    // }
    // return 0;
}