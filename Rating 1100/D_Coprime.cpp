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

const int B = 1001;
vector<vl> m(B);

ll gcd(ll a, ll b)
{
    return (b == 0) ? a : gcd(b, a % b);
}

void precompute()
{
    for (ll p = 1; p < B; ++p)
    {
        for (ll q = 1; q < B; ++q)
        {
            if (gcd(p, q) > 1)
                continue;
            m[p].pb(q);
            m[q].pb(p);
        }
    }
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> where(B, -1);
    for (ll i = 0; i < n; ++i)
    {
        ll x;
        cin >> x;
        where[x] = i + 1;
    }

    ll res = -1;
    for (ll p = 1; p < B; ++p)
    {
        if (where[p] < 0)
            continue;
        for (ll q : m[p])
        {
            if (where[q] < 0)
                continue;
            res = max(res, where[p] + where[q]);
        }
    }
    cout << res << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
