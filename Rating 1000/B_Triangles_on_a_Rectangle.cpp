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
    ll w, h;
    cin >> w >> h;
    ll res = 0;
    int k;
    cin >> k;
    vl bottom(k);
    for (int i = 0; i < k; i++)
    {
        cin >> bottom[i];
    }
    ll base = bottom[k - 1] - bottom[0];
    ll area = base * h;
    res = max(res, area);
    cin >> k;
    vl top(k);
    for (int i = 0; i < k; i++)
    {
        cin >> top[i];
    }
    base = top[k - 1] - top[0];
    area = base * h;
    res = max(res, area);
    cin >> k;
    vl left(k);
    for (int i = 0; i < k; i++)
    {
        cin >> left[i];
    }
    base = left[k - 1] - left[0];
    area = base * w;
    res = max(res, area);
    cin >> k;
    vl right(k);
    for (int i = 0; i < k; i++)
    {
        cin >> right[i];
    }
    base = right[k - 1] - right[0];
    area = base * w;
    res = max(res, area);
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