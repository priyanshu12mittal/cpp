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
    int total = 0;
    int left = 0;
    int right = n - 1;
    int currA = 0;
    int currB = 0;
    while (left <= right)
    {
        if (currA <= currB)
        {
            currA += a[left++];
        }
        else
        {
            currB += a[right--];
        }
        if (currA == currB)
        {
            total = left + (n - right - 1);
        }
    }
    cout << total << endl;
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