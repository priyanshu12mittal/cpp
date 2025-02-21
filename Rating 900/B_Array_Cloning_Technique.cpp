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
    unordered_map<ll, ll> m;
    m.reserve(n);
    ll maxFreq = 0;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        maxFreq = max(maxFreq, ++m[x]);
    }
    int res = 0;
    while (n > maxFreq)
    {
        res++;
        int temp = min(n - maxFreq, maxFreq);
        res += temp;
        maxFreq += temp;
    }
    cout << res << endl;
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
