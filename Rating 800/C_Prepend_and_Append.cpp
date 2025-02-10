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
    string s;
    cin >> s;
    int i = 0;
    int j = n-1;
    while (i < j) {
        if (s[i] != s[j]) {
            i++;
            j--;
        }
        else{
            break;
        }
    }

    cout << j-i+1<< endl;

}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

