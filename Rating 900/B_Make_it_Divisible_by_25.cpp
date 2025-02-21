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
    vector<string> v = {"00", "25", "50", "75"};
    int res = n;
    for (auto t : v)
    {
        char a = t[0], b = t[1];
        int moves = 0;
        int lastPos = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == b)
            {
                lastPos = i;
                break;
            }
            else
            {
                moves++;
            }
        }
        if (lastPos == -1)
        {
            continue;
        }
        int moves2 = 0;
        int lastPos2 = -1;
        for (int i = lastPos - 1; i >= 0; i--)
        {
            if (s[i] == a)
            {
                lastPos2 = i;
                break;
            }
            else
            {
                moves2++;
            }
        }
        if (lastPos2 == -1)
        {
            continue;
        }
        res = min(res, moves + moves2);
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
