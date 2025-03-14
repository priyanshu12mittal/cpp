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
    int n, q;
    cin >> n >> q;
    vl a(n);
    vl Q(q);
    vl prefix(n), currMax(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        prefix[i] = a[i];
    }
    prefix[0] = a[0];
    currMax[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + a[i];
        currMax[i] = max(currMax[i - 1], a[i]);
    }
    while (q--)
    {
        ll k;
        cin >> k;
        auto pos = upper_bound(all(currMax), k);
        if (pos == currMax.begin())
        {
            cout << 0 << " ";
        }
        else
        {
            cout << prefix[int(pos - currMax.begin()) - 1] << " ";
        }
    }
    cout << "\n";
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