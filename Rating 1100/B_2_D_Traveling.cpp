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
ll distance(const pll &p, const pll &q)
{
    return abs(p.first - q.first) + abs(p.second - q.second);
}
void solve()
{
    int n, k, a, b;
    cin >> n >> k >> a >> b;
    vector<pll> cords(n);
    for (int i = 0; i < n; i++)
    {
        cin >> cords[i].first >> cords[i].second;
    }
    ll direct = distance(cords[a - 1], cords[b - 1]);
    if (k == 0)
    {
        cout << direct << "\n";
        return;
    }
    ll costA;
    ll costB;
    if (a <= k)
    {
        costA = 0;
    }
    else
    {
        costA = LLONG_MAX;
        for (int i = 0; i < k; i++)
        {
            costA = min(costA, distance(cords[a - 1], cords[i]));
        }
    }
    if (b <= k)
    {
        costB = 0;
    }
    else
    {
        costB = LLONG_MAX;
        for (int i = 0; i < k; i++)
        {
            costB = min(costB, distance(cords[b - 1], cords[i]));
        }
    }
    cout << min(direct, costA + costB) << "\n";
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