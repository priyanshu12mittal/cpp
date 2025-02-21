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
    int n, p;
    cin >> n >> p;
    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vi b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    vector<pair<int, int>> pairs;
    for (size_t i = 0; i < a.size(); i++)
    {
        pairs.push_back({a[i], b[i]});
    }
    sort(pairs.begin(), pairs.end(), [](const pair<int, int> &p1, const pair<int, int> &p2)
         { return p1.second < p2.second; });
    ll ans = p;
    int count = 1;
    for (auto &pair : pairs)
    {
        int helmet = pair.first;
        int light = pair.second;
        while (count < n && helmet > 0)
        {
            if (light >= p)
            {
                ans += (ll)(n - count) * p;
                count = n;
                break;
            }
            ans += light;
            helmet--;
            count++;
        }
        if (count == n)
        {
            break;
        }
    }
    cout << ans << endl;
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
