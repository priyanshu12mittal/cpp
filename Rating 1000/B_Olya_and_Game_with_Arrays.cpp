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
    ll SecSum = 0;
    ll gloablFirst = LLONG_MAX;
    ll gloablSecond = LLONG_MAX;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        ll firstMin = LLONG_MAX;
        ll secondMin = LLONG_MAX;
        for (int j = 0; j < m; j++)
        {
            ll x;
            cin >> x;
            if (x < firstMin)
            {
                secondMin = firstMin;
                firstMin = x;
            }
            else if (x < secondMin)
            {
                secondMin = x;
            }
        }
        if (secondMin == LLONG_MAX)
        {
            secondMin = firstMin;
        }
        SecSum += secondMin;
        gloablFirst = min(gloablFirst, firstMin);
        gloablSecond = min(gloablSecond, secondMin);
    }
    cout << SecSum + gloablFirst - gloablSecond << endl;
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
