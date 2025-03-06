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
    int n = sz(s);
    bool allOnes = true;
    for (char c : s)
    {
        if (c == '0')
        {
            allOnes = false;
            break;
        }
    }
    if (allOnes)
    {
        cout << (ll)n * n << "\n";
        return;
    }
    int maxLen = 0;
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            len++;
        }
        else
        {
            maxLen = max(maxLen, len);
            len = 0;
        }
    }
    maxLen = max(maxLen, len);
    int prefix = 0, suffix = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
            prefix++;
        else
            break;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '1')
            suffix++;
        else
            break;
    }
    maxLen = max(maxLen, prefix + suffix);
    int a = (maxLen + 1) / 2;
    int b = (maxLen + 1) - a;
    ll area = (ll)a * b;
    cout << area << "\n";
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