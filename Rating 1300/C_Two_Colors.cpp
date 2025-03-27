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
    int n, m;
    cin >> n >> m;
    vi a(m);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    vi first(m), second(m);
    for (int i = 0; i < m; i++)
    {
        first[i] = min(a[i], n - 1);
        second[i] = max(1, n - a[i]);
    }
    vi sec_sort = second;
    sort(all(sec_sort));
    vl prefix(m + 1, 0);
    for (int i = 0; i < m; i++)
    {
        prefix[i + 1] = prefix[i] + sec_sort[i];
    }
    ll ans = 0;
    for (int i = 0; i < m; i++)
    {
        int xi = first[i];
        int li = second[i];
        int pos = upper_bound(all(sec_sort), xi) - sec_sort.begin();
        ll cnt = pos;
        ll sumL = prefix[pos];
        if (li <= xi)
        {
            cnt--;
            sumL -= li;
        }
        if (cnt > 0)
        {
            ans += cnt * ((ll)xi + 1) - sumL;
        }
    }

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