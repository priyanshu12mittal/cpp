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
        cin >> a[i];
    int finalL = 0, finalR = 0;
    int bestDiff = 0;
    for (int l = 0; l < n; l++)
    {
        int diff = 0;
        for (int r = l + 1; r < n; r++)
        {
            if (a[r] > a[l])
                diff += 1;
            else if (a[r] < a[l])
                diff -= 1;
            if (diff < bestDiff)
            {
                bestDiff = diff;
                finalL = l;
                finalR = r;
            }
        }
    }
    cout << finalL + 1 << " " << finalR + 1 << endl;
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