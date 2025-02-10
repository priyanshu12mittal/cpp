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
    int x,k;
    cin >> x >> k;
    if (x%k==0) {
        cout << 2 << endl;
        cout <<1 << " "<< x-1<< endl;

    }
    else {
        cout << 1 << endl;
        cout << x << endl;

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

