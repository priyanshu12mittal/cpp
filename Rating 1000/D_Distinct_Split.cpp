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
    vi prefix(n, 0), suffix(n, 0);
    vector<bool> seen(26, false);
    int unique = 0;
    for (int i = 0; i < n; i++)
    {
        int idx = s[i] - 'a';
        if (!seen[idx])
        {
            unique++;
            seen[idx] = true;
        }
        prefix[i] = unique;
    }
    fill(seen.begin(), seen.end(), false);
    unique = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int idx = s[i] - 'a';
        if (!seen[idx])
        {
            unique++;
            seen[idx] = true;
        }
        suffix[i] = unique;
    }
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        ans = max(ans, prefix[i] + suffix[i + 1]);
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