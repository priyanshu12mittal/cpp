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
bool isPower(ll n)
{
    return (n > 0) && ((n & (n - 1)) == 0);
}
void solve()
{
    ll n;
    cin >> n;
    if (isPower(n) || isPower(n + 1))
    {
        cout << -1 << endl;
        return;
    }
    int m = 0;
    for (int i = 63; i >= 0; i--)
    {
        if (n & (1LL << i))
        {
            m = i;
            break;
        }
    }
    int r = -1, p = -1;
    for (int i = 0; i < m; i++)
    {
        if ((n >> i) & 1LL)
        {
            if (r == -1)
                r = i;
        }
        else
        {
            if (p == -1)
                p = i;
        }
    }
    ll y = (1LL << r) + (1LL << p);
    cout << y << "\n";
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