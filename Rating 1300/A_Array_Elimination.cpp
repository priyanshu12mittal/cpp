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
    int n;
    cin >> n;
    vl a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vi cnt(31, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= 30; j++)
        {
            if ((a[i] & (1LL << j)))
            {
                cnt[j]++;
            }
        }
    }
    int g = 0;
    for (int bit = 0; bit < 31; bit++)
    {
        if (cnt[bit] > 0)
        {
            g = gcd(g, cnt[bit]);
        }
    }

    for (int k = 1; k <= n; k++)
    {
        if (g % k == 0)
        {
            cout << k << " ";
        }
    }
    cout << endl;
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