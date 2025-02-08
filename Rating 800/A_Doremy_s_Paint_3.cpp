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
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            cnt[a[i]]++;
        }
        if (cnt.size() > 2) {
            cout << "No" << endl;
        }
        else{
            int freq1 = cnt.begin()->second, freq2 = cnt.rbegin()->second;
            if (freq1 == freq2) {
                cout << "Yes" << endl;
            }
            else if (n % 2 == 1 && abs(freq1 - freq2) == 1) {
                cout << "Yes" << endl;
            }
            else{
                cout << "No" << endl;
            }

        }
    }
    return 0;
}

