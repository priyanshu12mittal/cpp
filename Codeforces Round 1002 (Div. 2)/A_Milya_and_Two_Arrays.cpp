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
        vector <int> a(n), b(n);
        for (int &x : a) cin >> x;
        for (int &x : b) cin >> x;

        set <int> uniqueA(all(a));
        set <int> uniqueB(all(b));

        if (uniqueA.size() == 1 && uniqueB.size() == 1) {
            cout << "NO" << endl;
            continue;
        }

        set <int> unique;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                unique.insert(a[i] + b[j]);
            }
        }
        if (unique.size() >= 3) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;

}

