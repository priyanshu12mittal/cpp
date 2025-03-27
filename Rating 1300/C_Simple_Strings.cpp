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
    string s;
    cin >> s;
    int n = sz(s);
    for (int i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1])
        {
            for (char c = 'a'; c <= 'z'; ++c)
            {
                if (c != s[i - 1] && (i == n - 1 || c != s[i + 1]))
                {
                    s[i] = c;
                    break;
                }
            }
        }
    }
    cout << s << endl;
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