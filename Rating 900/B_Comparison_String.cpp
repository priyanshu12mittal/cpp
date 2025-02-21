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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int maxLen = 0;
    int curr = 1;
    char prev = s[0];
    for (int i = 1; i < n; i++)
    {
        if (s[i] == prev)
        {
            curr++;
        }
        else
        {
            maxLen = max(maxLen, curr);
            curr = 1;
            prev = s[i];
        }
    }
    maxLen = max(maxLen, curr);
    cout << maxLen + 1 << endl;
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
