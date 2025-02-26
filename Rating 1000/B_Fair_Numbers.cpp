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

bool isFair(ll x)
{
    ll org = x;
    while (x)
    {
        int dig = x % 10;
        x /= 10;
        if (dig != 0 && org % dig != 0)
            return false;
    }
    return true;
}

void solve()
{
    ll n;
    cin >> n;
    while (!isFair(n))
    {
        n++;
    }
    cout << n << endl;
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