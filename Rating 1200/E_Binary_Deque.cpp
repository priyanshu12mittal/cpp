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
    int n, s;
    cin >> n >> s;
    vi a(n);
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        total += a[i];
    }
    if (total < s)
    {
        cout << -1 << "\n";
        return;
    }
    if (total == s)
    {
        cout << 0 << "\n";
        return;
    }
    int maxLen = -1;
    int currSum = 0;
    int l = 0;
    for (int r = 0; r < n; r++)
    {
        currSum += a[r];
        while (l <= r && currSum > s)
        {
            currSum -= a[l];
            l++;
        }
        if (currSum == s)
        {
            maxLen = max(maxLen, r - l + 1);
        }
    }
    if (maxLen == -1)
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << n - maxLen << "\n";
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