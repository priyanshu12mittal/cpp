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

ll helper(int k, int m, ll n)
{
    ll sum = 1, term = 1;
    for (int i = 1; i < m; i++)
    {
        if (term > LLONG_MAX / k)
            return n + 1;
        term *= k;
        if (sum > LLONG_MAX - term)
            return n + 1;
        sum += term;
        if (sum > n)
            break;
    }
    return sum;
}
void solve()
{
    ll n;
    cin >> n;
    int maxM = floor(log2(n + 1)) + 1;
    for (int m = 3; m <= maxM; m++)
    {
        int lo = 2, hi = n;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            ll sum = helper(mid, m, n);
            if (sum == n)
            {
                cout << "YES" << endl;
                return;
            }
            else if (sum < n)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
    }
    cout << "NO" << endl;
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