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
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }
    vector<int> rpre(n, 0);
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '1')
                cnt++;
            else
                break;
        }
        rpre[i] = cnt;
    }
    vector<int> cpre(m, 0);
    for (int j = 0; j < m; j++)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (grid[i][j] == '1')
                cnt++;
            else
                break;
        }
        cpre[j] = cnt;
    }

    bool possible = true;
    for (int i = 0; i < n && possible; i++)
    {
        for (int j = 0; j < m && possible; j++)
        {
            if (grid[i][j] == '1')
            {
                if ((j + 1 > rpre[i]) && (i + 1 > cpre[j]))
                {
                    possible = false;
                }
            }
            else
            {
                if ((j + 1 <= rpre[i]) || (i + 1 <= cpre[j]))
                {
                    possible = false;
                }
            }
        }
    }

    cout << (possible ? "YES" : "NO") << "\n";
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