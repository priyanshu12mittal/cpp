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
    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }

    int first = a[n - 1] - a[0];
    int minPrefix = a[0];
    int maxSuffix = a[n - 1];
    for (int i = 0; i < n - 1; i++)
    {
        minPrefix = min(minPrefix, a[i]);
    }
    for (int i = 1; i < n; i++)
    {
        maxSuffix = max(maxSuffix, a[i]);
    }
    int second = a[n - 1] - minPrefix;
    int third = maxSuffix - a[0];
    int four = INT_MIN;
    for (int i = 0; i < n - 1; i++)
    {
        four = max(four, a[i] - a[i + 1]);
    }
    cout << max({first, second, third, four}) << endl;
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
