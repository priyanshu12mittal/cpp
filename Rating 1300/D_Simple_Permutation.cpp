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
vector<bool> sieve(int maxVal)
{
    vector<bool> isPrime(maxVal + 1, true);
    if (maxVal >= 0)
        isPrime[0] = false;
    if (maxVal >= 1)
        isPrime[1] = false;
    for (int i = 2; i * i <= maxVal; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= maxVal; j += i)
                isPrime[j] = false;
        }
    }
    return isPrime;
}

void solve()
{
    int n;
    cin >> n;
    vector<bool> isPrime = sieve(n);
    set<int> avail;
    for (int i = 1; i <= n; i++)
    {
        avail.insert(i);
    }

    ll S = 0;
    vector<int> res;
    res.reserve(n);
    for (int i = 1; i <= n; i++)
    {
        int chosen = -1;
        if (avail.empty())
            break;
        int x_min = *avail.begin();
        int x_max = *avail.rbegin();
        int c_min = (int)((S + x_min + i - 1) / i);
        int c_max = (int)((S + x_max + i - 1) / i);
        for (int c = c_min; c <= c_max; c++)
        {
            if (!isPrime[c])
                continue;
            ll L = (ll)(c - 1) * i - S + 1;
            ll R = (ll)c * i - S;
            if (L < 1)
                L = 1;
            auto it = avail.lower_bound((int)L);
            if (it != avail.end() && *it <= R)
            {
                chosen = *it;
                break;
            }
        }
        if (chosen == -1)
        {
            chosen = *avail.rbegin();
        }
        res.push_back(chosen);
        S += chosen;
        avail.erase(chosen);
    }
    for (int x : res)
        cout << x << " ";
    cout << "\n";
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
