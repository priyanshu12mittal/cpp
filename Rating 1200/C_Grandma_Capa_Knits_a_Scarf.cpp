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

bool helper(const string &s, char ch, int &removed)
{
    int i = 0, j = s.size() - 1;
    removed = 0;
    while (i < j)
    {
        if (s[i] == s[j])
        {
            i++;
            j--;
        }
        else if (s[i] == ch)
        {
            removed++;
            i++;
        }
        else if (s[j] == ch)
        {
            removed++;
            j--;
        }
        else
        {
            return false;
        }
    }
    return true;
}
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int res = n + 1;
    bool poss = false;
    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        int removed = 0;
        if (helper(s, ch, removed))
        {
            res = min(res, removed);
            poss = true;
        }
    }
    if (poss)
    {
        cout << res << endl;
    }
    else
    {
        cout << -1 << endl;
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