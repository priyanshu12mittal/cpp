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
    int n, m;
    cin >> n >> m;
    vl a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vl b(m);
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    ll last = -1e18;
    bool possible = true;
    for (int i = 0; i < n; i++)
    {
        ll unch = a[i];
        ll chan = b[0] - a[i];
        ll cand1 = min(unch, chan);
        ll cand2 = max(unch, chan);
        if (cand1 >= last)
        {
            last = cand1;
        }
        else if (cand2 >= last)
        {
            last = cand2;
        }
        else
        {
            possible = false;
            break;
        }
    }
    cout << (possible ? "YES" : "NO") << "\n";
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
