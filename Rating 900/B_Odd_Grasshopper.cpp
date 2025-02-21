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
    ll xo, n;
    cin >> xo >> n;
    ll add;
    if (n % 4 == 0)
    {
        add = 0;
    }
    else if (n % 4 == 1)
    {
        add = n;
    }
    else if (n % 4 == 2)
    {
        add = -1;
    }
    else
    {
        add = -(n + 1);
    }

    if (xo % 2 == 0)
    {
        cout << xo - add << endl;
    }
    else
    {
        cout << xo + add << endl;
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
