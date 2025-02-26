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
    vi ans(n, 0);
    int i = 0;
    while (i < n)
    {
        int j = i;
        while (j < n && a[j] == a[i])
        {
            j++;
        }
        int grp = j - i;
        if (grp < 2)
        {
            cout << -1 << endl;
            return;
        }
        for (int k = i; k < j - 1; k++)
        {
            ans[k] = k + 2;
        }
        ans[j - 1] = i + 1;
        i = j;
    }
    for (int i = 0; i < n; i++)
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