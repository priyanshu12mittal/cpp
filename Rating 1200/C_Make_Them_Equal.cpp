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
    char c;
    cin >> n >> c;
    string s;
    cin >> s;
    bool all_same = true;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != c)
            all_same = false;
    }
    if (all_same)
    {
        cout << 0 << endl;
        return;
    }
    for (int i = 2; i <= n; i++)
    {
        bool flag = true;
        for (int j = i; j <= n; j += i)
        {
            if (s[j - 1] != c)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            cout << 1 << endl;
            cout << i << endl;
            return;
        }
    }
    cout << 2 << endl;
    cout << n << " " << n - 1 << endl;
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