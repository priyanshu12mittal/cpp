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

int helper(int x)
{
    int cnt = 0;
    while (x % 2 == 0)
    {
        cnt++;
        x /= 2;
    }
    return cnt;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (k == 2)
    {
        int ans = 0;
        bool even = false;
        for (int i = 0; i < n; i++)
        {
            if (a[i] % 2 == 0)
            {
                even = true;
                break;
            }
        }
        cout << (even ? 0 : 1) << "\n";
    }
    else if (k == 3)
    {
        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int rem = a[i] % 3;
            int cost = (3 - rem) % 3;
            ans = min(ans, cost);
        }
        cout << ans << "\n";
    }
    else if (k == 5)
    {
        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int rem = a[i] % 5;
            int cost = (5 - rem) % 5;
            ans = min(ans, cost);
        }
        cout << ans << "\n";
    }
    else
    {
        int Evens = 0;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += helper(a[i]);
            if (a[i] % 2 == 0)
                Evens++;
        }
        if (sum >= 2)
        {
            cout << 0 << "\n";
        }
        else
        {
            if (Evens == 1)
            {
                cout << 1 << "\n";
            }
            else
            {
                int best = INT_MAX;
                for (auto x : a)
                {
                    for (int y = 1; y <= 5; y++)
                    {
                        if (helper(x + y) >= 2)
                        {
                            best = min(best, y);
                            break;
                        }
                    }
                }
                int ans = min(best, 2);
                cout << ans << "\n";
            }
        }
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
