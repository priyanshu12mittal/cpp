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
    string s;
    cin >> s;
    ll dash = 0;
    ll uds = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '-')
            dash++;
        else if (s[i] == '_')
            uds++;
    }
    ll x = dash / 2;
    ll y = dash - x;
    cout << uds * x * y << endl;
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