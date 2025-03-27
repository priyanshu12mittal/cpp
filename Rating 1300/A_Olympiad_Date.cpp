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
    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int need0 = 3, need1 = 1, need2 = 2, need3 = 1, need5 = 1;
    int count0 = 0, count1 = 0, count2 = 0, count3 = 0, count5 = 0;
    int res = 0;

    for (int i = 0; i < n; i++)
    {
        int d = a[i];
        if (d == 0)
            count0++;
        if (d == 1)
            count1++;
        if (d == 2)
            count2++;
        if (d == 3)
            count3++;
        if (d == 5)
            count5++;

        if (count0 >= need0 && count1 >= need1 && count2 >= need2 && count3 >= need3 && count5 >= need5)
        {
            res = i + 1;
            break;
        }
    }

    cout << res << "\n";
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