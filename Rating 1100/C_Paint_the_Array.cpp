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
    vl a(n);
    forn(i, n)
    {
        cin >> a[i];
    }
    ll evenGcd = a[0];
    ll oddGcd = (n > 1) ? a[1] : 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            evenGcd = __gcd(evenGcd, a[i]);
        }
        else
        {
            oddGcd = __gcd(oddGcd, a[i]);
        }
    }
    bool odd = true;
    for (int i = 0; i < n; i += 2)
    {
        if (a[i] % oddGcd == 0)
        {
            odd = false;
            break;
        }
    }
    bool even = true;
    for (int i = 1; i < n; i += 2)
    {
        if (a[i] % evenGcd == 0)
        {
            even = false;
            break;
        }
    }
    ll res = 0;
    if (odd)
    {
        res = max(res, oddGcd);
    }
    if (even)
    {
        res = max(res, evenGcd);
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