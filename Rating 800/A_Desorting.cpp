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
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int minDiff = INT_MAX;
    for (int i = 0; i < n-1; i++) {
        minDiff = min(minDiff, a[i+1]-a[i]);
    }
    if (minDiff < 0 ){
        cout << 0 << endl;
    }
    else if (minDiff == 0) {
        cout << 1 << endl;
    }
    else {
        cout << minDiff/2 + 1 << endl;
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

