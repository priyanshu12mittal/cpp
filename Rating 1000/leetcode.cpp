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
int main()
{
    unsigned long long A, B, C;
    cin >> A >> B >> C;
    if (((A & B) & (~C)) != 0ULL)
    {
        cout << -1 << endl;
        return 0;
    }
    unsigned long long X = C & ~(A & B);

    cout << X << endl;
    return 0;
}
