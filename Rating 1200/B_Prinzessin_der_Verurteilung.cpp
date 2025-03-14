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

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool present[26] = {false};
    for (char ch : s)
    {
        present[ch - 'a'] = true;
    }
    for (int i = 0; i < 26; i++)
    {
        if (!present[i])
        {
            cout << char('a' + i) << endl;
            return;
        }
    }
    unordered_set<string> substr2;
    for (int i = 0; i < n - 1; i++)
    {
        substr2.insert(s.substr(i, 2));
    }
    for (char a = 'a'; a <= 'z'; a++)
    {
        for (char b = 'a'; b <= 'z'; b++)
        {
            string cand;
            cand.pb(a);
            cand.pb(b);
            if (substr2.find(cand) == substr2.end())
            {
                cout << cand << endl;
                return;
            }
        }
    }
    unordered_set<string> substr3;
    for (int i = 0; i < n - 2; i++)
    {
        substr3.insert(s.substr(i, 3));
    }
    for (char a = 'a'; a <= 'z'; a++)
    {
        for (char b = 'a'; b <= 'z'; b++)
        {
            for (char c = 'a'; c <= 'z'; c++)
            {
                string cand;
                cand.pb(a);
                cand.pb(b);
                cand.pb(c);
                if (substr3.find(cand) == substr3.end())
                {
                    cout << cand << endl;
                    return;
                }
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