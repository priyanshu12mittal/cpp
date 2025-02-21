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
    string s, t;
    cin >> s >> t;
    vvi pos(256);
    for (int i = 0; i < sz(s); i++)
    {
        pos[s[i]].pb(i);
    }
    vi freq(256, 0);
    for (char c : t)
    {
        freq[c]++;
    }
    bool possible = true;
    vi chosen;
    for (int ch = 0; ch < 256; ch++)
    {
        if (freq[ch] > 0)
        {
            if (pos[ch].size() < freq[ch])
            {
                possible = false;
                break;
            }
        }

        int start = pos[ch].size() - freq[ch];
        for (int i = start; i < pos[ch].size(); i++)
        {
            chosen.pb(pos[ch][i]);
        }
    }

    if (!possible)
    {
        cout << "NO" << endl;
        return;
    }

    sort(all(chosen));
    string cand;
    for (int idx : chosen)
    {
        cand.pb(s[idx]);
    }
    cout << (cand == t ? "YES" : "NO") << endl;
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
