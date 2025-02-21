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
const ll MOD = 998244353;
void solve()
{
    int n;
    cin >> n;

    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll cur2 = 0;
    ll curPow2 = 1;
    ll curInv2 = 1;
    ll S = 0;
    ll ones = 0;
    ll ans = 0;
    ll inv2 = (MOD + 1) / 2;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
        {
            S = (S + curInv2) % MOD;
            ones++;
        }
        else if (a[i] == 2)
        {
            cur2++;
            curPow2 = (curPow2 * 2) % MOD;
            curInv2 = (curInv2 * inv2) % MOD;
        }
        else if (a[i] == 3)
        {
            ll contri = (curPow2 * S) % MOD;
            contri = (contri - ones) % MOD;
            if (contri < 0)
                contri += MOD;
            ans = (ans + contri) % MOD;
        }
    }
    cout << ans % MOD << "\n";
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
