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
    string s;
    cin >> s;
    int n = s.size();
    int ones = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
            ones++;
    }
    int zeros = n - ones;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1' && zeros > 0)
        {
            zeros--;
        }
        else if (s[i] == '0' && ones > 0)
        {
            ones--;
        }
        else
        {
            ans = n - i;
            break;
        }
    }
    cout << ans << endl;
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
