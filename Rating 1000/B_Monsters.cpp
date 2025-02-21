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
    vl a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<pair<long long, int>> monsters;
    for (int i = 0; i < n; i++)
    {
        long long key = (a[i] - 1) % k;
        monsters.push_back({key, i + 1});
    }
    sort(monsters.begin(), monsters.end(), [&](const pair<long long, int> &p1, const pair<long long, int> &p2)
         {
        if(p1.first == p2.first)
            return p1.second < p2.second;
        return p1.first > p2.first; });
    for (auto &p : monsters)
    {
        cout << p.second << " ";
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