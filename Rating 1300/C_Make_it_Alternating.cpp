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
ll MOD = 998244353;

void solve()
{
    string s;
    cin >> s;
    int n = sz(s);
    vi blocks;
    ll ans = 1;
    for (int i = 0; i < n;)
    {
        int j = i;
        while (j < n && s[i] == s[j])
        {
            j++;
        }
        blocks.pb(j - i);
        i = j;
    }
    int k = sz(blocks);
    cout << n - k << " ";
    for (int len : blocks)
    {
        ans = (ans * (len % MOD)) % MOD;
    }
    ll fact = 1;
    for (int i = 1; i <= n - k; i++)
    {
        fact = (fact * i) % MOD;
    }
    ans = (ans * fact) % MOD;
    cout << ans << endl;
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