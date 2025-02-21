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
    vi b(n);
    for (int i = 0; i < n; i++)
        cin >> b[i];
    unordered_map<int, int> A;
    unordered_map<int, int> B;
    for (int i = 0; i < n;)
    {
        int x = a[i];
        int count = 0;
        while (i < n && x == a[i])
        {
            count++;
            i++;
        }
        A[x] = max(A[x], count);
    }
    for (int i = 0; i < n;)
    {
        int x = b[i];
        int count = 0;
        while (i < n && x == b[i])
        {
            count++;
            i++;
        }
        B[x] = max(B[x], count);
    }
    int res = 0;
    for (auto &p : A)
    {
        int x = p.first;
        int times = p.second;
        if (B.count(x))
        {
            times += B[x];
        }
        res = max(res, times);
    }
    for (auto &p : B)
    {
        res = max(res, p.second);
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