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
    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> ans;
    int L = 0, R = n - 1;
    while (L < R)
    {
        ans.push_back(a[L]);
        ans.push_back(a[R]);
        L++;
        R--;
    }
    if (L == R)
    {
        ans.push_back(a[L]);
    }
    int curr = 0;
    for (int i = 0; i < n; i++)
    {
        if (curr == ans[i])
        {
            cout << "NO" << endl;
            return;
        }
        curr += ans[i];
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
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
