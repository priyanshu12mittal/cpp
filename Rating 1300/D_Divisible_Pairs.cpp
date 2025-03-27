#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
    {
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        map<pair<int, int>, int> mpp;
        ll ans = 0;

        for (int i = 0; i < n; i++)
        {
            auto itr = mpp.find({(x - a[i] % x) % x, a[i] % y});
            if (itr != mpp.end())
            {
                ans += itr->second;
            }
            mpp[{a[i] % x, a[i] % y}]++;
        }
        cout << ans << "\n";
    }

    return 0;
}
