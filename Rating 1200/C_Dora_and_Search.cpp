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
    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int MIN = 1;
    int MAX = n;
    int l = 0, r = n - 1;
    while (l <= r)
    {
        if (a[l] == MIN)
        {
            l++;
            MIN++;
        }
        else if (a[l] == MAX)
        {
            l++;
            MAX--;
        }
        else if (a[r] == MIN)
        {
            r--;
            MIN++;
        }
        else if (a[r] == MAX)
        {
            r--;
            MAX--;
        }
        else
        {
            break;
        }
    }
    if (l <= r)
    {
        cout << l + 1 << " " << r + 1 << endl;
    }
    else
    {
        cout << -1 << endl;
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