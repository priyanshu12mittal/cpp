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
    map<ll, ll> count;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        count[x]++;
    }
    ll res = 0;
    for (auto &p : count)
    {
        while (p.second > 0)
        {
            res++;
            ll curr = p.first;
            while (count[curr] > 0)
            {
                count[curr]--;
                curr++;
            }
        }
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