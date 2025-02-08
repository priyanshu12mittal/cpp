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


int main() {
    int t;
    cin >> t;
    while (t--) {
        int res = 0;
        for (int i = 0; i < 10; i++) {
            string row;
            cin >> row;
            for (int j = 0; j < 10; j++) {
                if (row[j] == 'X') {
                    res += min({i, 9 - i, j, 9 - j}) + 1;                                                                                                                  
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}

