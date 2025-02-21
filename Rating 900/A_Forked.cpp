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
    ll a, b, xk, yk, xq, yq;
    cin >> a >> b >> xk >> yk >> xq >> yq;
    ll dx = xq - xk;
    ll dy = yq - yk;
    vector<pair<ll, ll>> moves = (a == b) ? vector<pair<ll, ll>>{
                                                {a, a}, {a, -a}, {-a, a}, {-a, -a}}
                                          : vector<pair<long long, long long>>{{a, b}, {a, -b}, {-a, b}, {-a, -b}, {b, a}, {b, -a}, {-b, a}, {-b, -a}};
    int res = 0;
    for (auto r : moves)
    {
        ll x = dx + r.first;
        ll y = dy + r.second;
        for (auto move : moves)
        {
            if (move.first == x && move.second == y)
            {
                res++;
                break;
            }
        }
    }
    cout << res << '\n';
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
