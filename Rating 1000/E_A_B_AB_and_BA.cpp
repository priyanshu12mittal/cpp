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
    string s;
    cin >> s;
    ll a, b, ab, ba;
    cin >> a >> b >> ab >> ba;
    ll n = s.size();
    int cntA = 0, cntB = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'A')
            cntA++;
        else
            cntB++;
    }
    if (cntA < a || cntB < b || (cntA - a) != (cntB - b))
    {
        cout << "NO\n";
        return;
    }
    int need = cntA - a;
    if (need > ab + ba)
    {
        cout << "NO\n";
        return;
    }
    vector<string> segs;
    for (int i = 0; i < n;)
    {
        int j = i;
        while (j + 1 < n && s[j + 1] != s[j])
            j++;
        segs.push_back(s.substr(i, j - i + 1));
        i = j + 1;
    }
    ll forced = 0;
    ll max_possible = 0;
    int flexCount = 0;
    for (auto &seg : segs)
    {
        int L = seg.size();
        if (L < 2)
            continue;
        if (seg.front() == seg.back())
        {
            forced += L / 2;
            max_possible += L / 2;
        }
        else
        {
            if (L % 2 == 1)
            {
                forced += L / 2;
                max_possible += L / 2;
            }
            else
            {
                forced += (L / 2 - 1);
                max_possible += L / 2;
                flexCount++;
            }
        }
    }
    if (need > max_possible)
    {
        if (need < forced)
        {
            cout << "YES\n";
            return;
        }
        else if (need <= forced + flexCount)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    else
    {
        cout << "NO\n";
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
