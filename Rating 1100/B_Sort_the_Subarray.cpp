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
    vi a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    int left = -1, right = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            left = i;
            break;
        }
    }
    if (left == -1)
    {
        cout << 1 << " " << n << "\n";
        return;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] != b[i])
        {
            right = i;
            break;
        }
    }
    int min_val = *min_element(a.begin() + left, a.begin() + right + 1);
    int max_val = *max_element(a.begin() + left, a.begin() + right + 1);
    while (left > 0 && a[left - 1] <= min_val)
    {
        left--;
        min_val = min(min_val, a[left]);
    }
    while (right < n - 1 && a[right + 1] >= max_val)
    {
        right++;
        max_val = max(max_val, a[right]);
    }
    cout << left + 1 << " " << right + 1 << "\n";
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