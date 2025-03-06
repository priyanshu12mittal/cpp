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
    vl a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Correctly initialize prefix sum
    vl prefix(n), suffix(n);
    prefix[0] = a[0]; // Set the first prefix element correctly
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + a[i];
    }

    suffix[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suffix[i] = suffix[i + 1] + a[i];
    }

    ll res = 0;
    for (int i = 1; i < n; i++)
    {
        ll curr = gcd(prefix[i - 1], suffix[i]);
        res = max(res, curr);
    }
    cout << res << endl;
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
