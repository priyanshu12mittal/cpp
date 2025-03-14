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

struct Interval
{
    ll start, end;
};
void solve()
{
    int n, m;
    cin >> n >> m;
    vl centers(n);
    vi radius(n);
    for (int i = 0; i < n; i++)
    {
        cin >> centers[i];
    }
    int maxRad = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> radius[i];
        maxRad = max(maxRad, radius[i]);
    }
    ll ans = 0;
    for (int y = -maxRad; y <= maxRad; y++)
    {
        vector<Interval> intervals;
        for (int i = 0; i < n; i++)
        {
            if (abs(y) <= radius[i])
            {
                int d = (int)floor(sqrt((double)radius[i] * radius[i] - (double)y * y));
                ll L = centers[i] - d;
                ll R = centers[i] + d;
                intervals.push_back({L, R});
            }
        }
        if (intervals.empty())
        {
            continue;
        }
        sort(all(intervals), [](const Interval &a, const Interval &b)
             { return a.start < b.start; });
        ll ms = intervals[0].start;
        ll me = intervals[0].end;
        ll countY = 0;
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i].start <= me + 1)
            {
                me = max(me, intervals[i].end);
            }
            else
            {
                countY += (me - ms + 1);
                ms = intervals[i].start;
                me = intervals[i].end;
            }
        }
        countY += (me - ms + 1);
        ans += countY;
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