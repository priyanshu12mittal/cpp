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
#define pli pair<ll, int>

void solve()
{
    int n;
    cin >> n;
    vector<pli> a, b, c;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        a.push_back({x, i});
    }
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        b.push_back({x, i});
    }
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        c.push_back({x, i});
    }
    auto cmp = [](const pli &p1, const pli &p2)
    {
        return p1.first > p2.first;
    };
    sort(all(a), cmp);
    sort(all(b), cmp);
    sort(all(c), cmp);
    int K = min(n, 3);

    ll best = LLONG_MIN;
    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < K; j++)
        {
            for (int k = 0; k < K; k++)
            {
                int day1 = a[i].second;
                int day2 = b[j].second;
                int day3 = c[k].second;
                if (day1 != day2 && day1 != day3 && day2 != day3)
                {
                    ll currentSum = a[i].first + b[j].first + c[k].first;
                    best = max(best, currentSum);
                }
            }
        }
    }
    cout << best << endl;
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