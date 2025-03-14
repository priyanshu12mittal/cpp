#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    ll prefix = 0;
    for (int i = 0; i < n; i++)
    {
        prefix += a[i];
        if (prefix > x)
            break;
        ll d_max = (x - prefix) / (i + 1);
        ans += d_max + 1;
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
