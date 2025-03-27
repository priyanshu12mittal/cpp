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
ll sumKLargest(const vector<ll> &vec, int k)
{
    if ((int)vec.size() < k)
        return -1e18;
    vector<ll> temp = vec;
    sort(temp.begin(), temp.end(), greater<ll>());
    ll sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += temp[i];
    }
    return sum;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll ans = -1e18;
    if (n - 1 >= k)
    {
        vector<ll> rightSide(a.begin() + 1, a.end());
        ll candidateCost = a[0] + sumKLargest(rightSide, k);
        ans = max(ans, candidateCost);
    }
    if (n - 1 >= k)
    {
        vector<ll> leftSide(a.begin(), a.end() - 1);
        ll candidateCost = a[n - 1] + sumKLargest(leftSide, k);
        ans = max(ans, candidateCost);
    }
    for (int L = 1; L < n - 1; L++)
    {
        vector<ll> leftSeg(a.begin(), a.begin() + L);
        sort(leftSeg.begin(), leftSeg.end(), greater<ll>());
        vector<ll> leftPrefix(leftSeg.size() + 1, 0);
        for (size_t i = 0; i < leftSeg.size(); i++)
        {
            leftPrefix[i + 1] = leftPrefix[i] + leftSeg[i];
        }
        vector<ll> rightSeg(a.begin() + L + 1, a.end());
        sort(rightSeg.begin(), rightSeg.end(), greater<ll>());
        vector<ll> rightPrefix(rightSeg.size() + 1, 0);
        for (size_t i = 0; i < rightSeg.size(); i++)
        {
            rightPrefix[i + 1] = rightPrefix[i] + rightSeg[i];
        }

        for (int t = 1; t <= k - 1; t++)
        {
            if (t <= (int)leftSeg.size() && (k - t) <= (int)rightSeg.size())
            {
                ll candidateCost = a[L] + leftPrefix[t] + rightPrefix[k - t];
                ans = max(ans, candidateCost);
            }
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