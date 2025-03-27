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
int helper(const vector<int> &sub)
{
    int n = sub.size();
    vector<bool> present(n + 2, false);
    for (int x : sub)
    {
        if (x < (int)present.size())
            present[x] = true;
    }
    for (int i = 0; i < (int)present.size(); i++)
    {
        if (!present[i])
            return i;
    }
    return 0;
}
void solve()
{
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<pii> ops;
    while (a.size() > 1)
    {
        bool hasZero = false;
        int pos = -1;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] == 0)
            {
                hasZero = true;
                pos = i;
                break;
            }
        }
        if (hasZero)
        {
            int l, r;
            if (pos < a.size() - 1)
            {
                l = pos;
                r = pos + 1;
            }
            else
            {
                l = pos - 1;
                r = pos;
            }
            vector<int> sub;
            for (int i = l; i <= r; i++)
            {
                sub.pb(a[i]);
            }
            int m = helper(sub);
            ops.pb({l + 1, r + 1});
            a.erase(a.begin() + l, a.begin() + r + 1);
            a.insert(a.begin() + l, m);
        }
        else
        {
            int l = 0, r = a.size() - 1;
            int m = helper(a);
            ops.pb({l + 1, r + 1});
            a.clear();
            a.pb(m);
        }
    }
    cout << ops.size() << "\n";
    for (auto &op : ops)
    {
        cout << op.first << " " << op.second << "\n";
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