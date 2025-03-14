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
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    bool allEqual = true;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != a[0])
        {
            allEqual = false;
            break;
        }
    }
    if (allEqual)
    {
        cout << "NO" << endl;
        return;
    }

    vector<pii> res;
    int idx = -1;
    for (int i = 1; i < n; i++)
    {
        if (a[0] != a[i])
        {
            idx = i;
            res.pb({1, i + 1});
        }
    }
    for (int i = 1; i < n; i++)
    {
        if (a[i] == a[0])
        {
            res.pb({idx + 1, i + 1});
        }
    }
    cout << "YES" << endl;
    for (pii p : res)
    {
        cout << p.first << " " << p.second << endl;
    }
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