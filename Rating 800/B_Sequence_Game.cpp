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
    ll n;
    cin >> n;
    vl b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vl a;
    a.pb(b[0]);
    for (int i = 1; i < n; i++) {
        if (b[i-1] <= b[i]) {
            a.pb(b[i]);
        }
        else {
            a.pb(b[i]);
            a.pb(b[i]);
        }
    }
    cout << sz(a) << endl;
    for (ll x:a) cout << x << " ";
    cout << endl;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

