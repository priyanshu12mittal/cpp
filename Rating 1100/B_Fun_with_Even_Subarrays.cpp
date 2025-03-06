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
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int final = a[n - 1];
    int res = 0;
    int currLen = 1;
    while (currLen < n)
    {
        if (n - currLen - 1 >= 0 && a[n - currLen - 1] == final)
        {
            currLen++;
        }
        else
        {
            res++;
            currLen *= 2;
        }
    }
    cout << res << endl;
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