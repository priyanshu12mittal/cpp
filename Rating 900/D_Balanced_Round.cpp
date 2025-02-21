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
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(all(a));
    int curr = 1;
    int maxLen = curr;
    int prev = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] - prev <= k)
        {
            curr++;
            prev = a[i];
        }
        else
        {
            prev = a[i];
            maxLen = max(maxLen, curr);
            curr = 1;
        }
    }
    maxLen = max(maxLen, curr);
    cout << n - maxLen << endl;
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
