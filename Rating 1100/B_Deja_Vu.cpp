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
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<ll> b;
    for (ll i = 0; i < q; i++)
    {
        ll x;
        cin >> x;
        if (b.empty() || b.back() > x)
            b.push_back(x);
    }

    vector<ll> w(b.size());
    ll acc = 0;
    for (int i = b.size() - 1; i >= 0; i--)
    {
        w[i] = (1LL << (b[i] - 1)) + acc;
        acc = w[i];
    }

    for (ll i = 0; i < n; i++)
    {
        for (size_t j = 0; j < b.size(); j++)
        {
            if (a[i] % (1LL << b[j]) == 0)
            {
                a[i] += w[j];
                break;
            }
        }
    }

    for (ll i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
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