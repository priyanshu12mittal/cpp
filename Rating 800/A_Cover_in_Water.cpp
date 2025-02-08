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
        int n;
        cin >> n;
        string a;
        cin >> a;
        int consecutive = 0;
        int max_consecutive = 0;
        int ans = 0;
        for (char ch : a) {
            if (ch == '.') {
                consecutive++;
            }
            else {
                if (consecutive > 0) {
                    if (consecutive > 2) {
                        max_consecutive = true;
                    }
                    else {
                        ans += consecutive;
                    }
                    consecutive = 0;
                }
            }
        }
        if (consecutive > 0) {
            if (consecutive > 2) {
                max_consecutive = true;
            }
            else {
                ans += consecutive;
            }
        }
        if (max_consecutive) {
            cout << 2 << endl;
        }
        else {
            cout << ans << endl;
        }
    }
    return 0;
}

