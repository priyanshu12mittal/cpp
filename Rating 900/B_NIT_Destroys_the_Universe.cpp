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
    ll n;
    cin >> n;
    vl a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    bool allZero = true;
    for (ll i = 0; i < n; i++)
    {
        if (a[i] != 0)
        {
            allZero = false;
            break;
        }
    }
    if (allZero)
    {
        cout << 0 << endl;
        return;
    }
    int L = 0, R = n - 1;
    while (L < n && a[L] == 0)
        L++;
    while (R >= 0 && a[R] == 0)
        R--;
    bool hasGap = false;
    for (int i = L; i <= R; i++)
    {
        if (a[i] == 0)
        {
            hasGap = true;
            break;
        }
    }
    if (!hasGap)
    {
        cout << 1 << endl;
        return;
    }
    else
    {
        cout << 2 << endl;
    }
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
