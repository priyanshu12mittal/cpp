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
    int n, q;
    cin >> n >> q;
    vl a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll total = 0;
    for (int i = 0; i < n; i++)
    {
        total += a[i];
    }
    int curr = 0;
    vi lastUpd(n, 0);
    ll res = 0;
    while (q--)
    {
        int t1;
        cin >> t1;
        if (t1 == 1)
        {
            int i;
            ll x;
            cin >> i >> x;
            i--;
            ll oldVal;
            if (lastUpd[i] == curr)
            {
                oldVal = a[i];
            }
            else
            {
                oldVal = res;
            }
            total = total - oldVal + x;
            a[i] = x;
            lastUpd[i] = curr;
            cout << total << "\n";
        }
        else
        {
            ll x;
            cin >> x;
            curr++;
            res = x;
            total = (long long)n * x;
            cout << total << "\n";
        }
    }
}
int main()
{
    // int t;
    // cin >> t;
    // while (t--)
    // {
    solve();
    // }
    return 0;
}