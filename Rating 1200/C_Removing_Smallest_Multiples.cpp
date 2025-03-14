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
    string s;
    cin >> s;
    ll total = 0;
    vector<bool> insideT(n + 1, false), removed(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        insideT[i] = (s[i - 1] == '1');
    }
    for (int x = 1; x <= n; x++)
    {
        for (int v = x; v <= n; v += x)
        {
            if (insideT[v])
            {
                break;
            }
            if (!removed[v])
            {
                removed[v] = true;
                total += x;
            }
        }
    }
    cout << total << "\n";
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