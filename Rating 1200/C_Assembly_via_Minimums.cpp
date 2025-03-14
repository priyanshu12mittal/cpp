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
    int n1 = (n * (n - 1)) / 2;
    vl a(n1);
    for (int i = 0; i < n1; i++)
    {
        cin >> a[i];
    }
    sort(all(a));
    int j = 0;
    int i = 1;
    while (j < n1)
    {
        cout << a[j] << " ";
        j += (n - i);
        i++;
    }
    cout << a[n1 - 1] << "\n";
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