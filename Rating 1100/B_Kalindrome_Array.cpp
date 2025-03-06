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

bool canForm(vi &a, int x)
{
    int i = 0, j = sz(a) - 1;
    while (i < j)
    {
        if (a[i] == a[j])
        {
            i++;
            j--;
        }
        else if (a[i] == x)
        {
            i++;
        }
        else if (a[j] == x)
        {
            j--;
        }
        else
        {
            return false;
        }
    }
    return true;
}

void solve()
{
    int n;
    cin >> n;
    vi a(n);
    forn(i, n)
    {
        cin >> a[i];
    }
    if (a == vi(a.rbegin(), a.rend()))
    {
        cout << "YES" << endl;
        return;
    }
    int i = 0, j = n - 1;
    while (i < j && a[i] == a[j])
    {
        i++;
        j--;
    }
    int x1 = a[i], x2 = a[j];
    if (canForm(a, x1) || canForm(a, x2))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
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