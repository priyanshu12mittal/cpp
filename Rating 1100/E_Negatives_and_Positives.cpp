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
    cin >> n;
    ll total = 0;
    ll negs = 0;
    ll MinEle = LLONG_MAX;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        if (x < 0)
        {
            negs++;
        }
        MinEle = min(MinEle, abs(x));
        total += abs(x);
    }
    if (negs % 2 == 0)
    {
        cout << total << "\n";
        return;
    }
    total -= 2 * MinEle;
    cout << total << "\n";
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