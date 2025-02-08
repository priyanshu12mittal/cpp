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


void solve() {
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (k == n) {
        for (int i = 1; i < n; i += 2) {
            if (a[i] != (i+1)/2) {
                cout << (i+1)/2 << endl;
                return;
            }
        }
        cout << k / 2 +1 << endl;
    }
    else{
        for (int i = 1; i < n - k + 2; i++) {
            if (a[i] != 1) {
                cout << 1 << endl;
                return;
            }
        }
        cout << 2 << endl;
    }
    
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;

}

