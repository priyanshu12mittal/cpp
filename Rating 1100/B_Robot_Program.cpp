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
    int x;
    ll k;
    cin >> n >> x >> k;
    string s;
    cin >> s;
    vl prefix(n, 0);
    for (int i = 0; i < n; i++)
    {
        ll del = (s[i] == 'R' ? 1 : -1);
        if (i == 0)
            prefix[i] = del;
        else
            prefix[i] = prefix[i - 1] + del;
    }
    int first = -1;
    for (int i = 0; i < n; i++)
    {
        if (x + prefix[i] == 0)
        {
            first = i + 1;
            break;
        }
    }
    if (first == -1 || first > k)
    {
        cout << 0 << "\n";
        return;
    }
    ll ans = 1;
    ll rem = k - first;
    int cmds = -1;
    for (int i = 0; i < n; i++)
    {
        if (prefix[i] == 0)
        {
            cmds = i + 1;
            break;
        }
    }
    if (cmds == -1)
    {
        cout << ans << "\n";
        return;
    }
    ans += rem / cmds;
    cout << ans << "\n";
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