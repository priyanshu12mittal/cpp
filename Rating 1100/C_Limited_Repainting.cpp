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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vl a(n);
    ll maxPen = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        maxPen = max(maxPen, a[i]);
    }
    ll low = 0;
    ll high = maxPen;
    ll ans = high;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        int ops = 0;
        int i = 0;
        bool possible = true;
        while (i < n)
        {
            if (a[i] > mid)
            {
                if (s[i] == 'R')
                {
                    i++;
                }
                else
                {
                    ops++;
                    if (ops > k)
                    {
                        possible = false;
                        break;
                    }
                    while (i < n && !(a[i] > mid && s[i] == 'R'))
                    {
                        i++;
                    }
                }
            }
            else
            {
                i++;
            }
        }

        if (possible && ops <= k)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << ans << "\n";
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