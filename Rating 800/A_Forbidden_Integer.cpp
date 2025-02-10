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
    int n, x, k;
    cin >> n >> k >> x;

    if (x != 1) {
        cout << "YES" << endl;
        cout << n << endl;
        for (int i = 0; i < n; i++) {
            cout << 1 << " ";
        }
        cout << endl;
    }

    else{
        if (k == 1) {
            cout <<"NO" << endl;
        }
        else if (k == 2) {
            if (n % 2 == 0) {
                cout << "YES" << endl;
                cout << n/2 << endl;
                for (int i = 0; i < n/2; i++) {
                    cout << 2 << " ";
                }
                cout << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }

        else{
            if (n == 1) {
                cout << "NO" << endl;
            }
            else if (n % 2 == 0){
                cout << "YES" << "\n";
                int cnt = n / 2;
                cout << cnt << "\n";
                for(int i = 0; i < cnt; i++){
                    cout << 2 << " ";
                }
                cout << "\n";
            }
            else{
                cout << "YES" << "\n";
                int cnt = 1 + (n - 3) / 2;
                cout << cnt << "\n";
                cout << 3 << " ";
                for(int i = 0; i < (n - 3) / 2; i++){
                    cout << 2 << " ";
                }
                cout << "\n";
            }
        }
        
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

