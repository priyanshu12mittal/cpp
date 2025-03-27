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
    if (n % 2 == 0)
    {
        cout << (n / 2 + 1) * (n / 2 + 1) << endl;
    }
    else
    {
        int k = (n - 1) / 2;
        cout << 2 * (k + 1) * (k + 2) << endl;
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
    // return 0;
}