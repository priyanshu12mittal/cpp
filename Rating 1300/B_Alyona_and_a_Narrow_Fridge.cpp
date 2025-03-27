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

bool canForm(vl &a, ll h)
{
    int n = sz(a);
    sort(a.rbegin(), a.rend());
    for (int i = 0; i < n; i += 2)
    {
        h -= a[i];
    }
    return h >= 0;
}
void solve()
{
    int n;
    ll h;
    cin >> n >> h;
    vl a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int lo = 1, hi = n;
    while (lo < hi)
    {
        int mid = lo + (hi - lo + 1) / 2;
        vl arr(a.begin(), a.begin() + mid);
        if (canForm(arr, h))
        {
            lo = mid;
        }
        else
        {
            hi = mid - 1;
        }
    }
    cout << lo << endl;
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