#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m, d;
        cin >> n >> m >> d;
        vector<string> grid(n);
        for (auto &s : grid)
            cin >> s;

        vector<vector<int>> holds(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 'X')
                    holds[i].push_back(j + 1);
            }
            sort(holds[i].begin(), holds[i].end());
        }
        bool valid = true;
        for (auto &v : holds)
            if (v.empty())
            {
                valid = false;
                break;
            }
        if (!valid)
        {
            cout << 0 << "\n";
            continue;
        }

        long long dd = (long long)d * d;
        int R = (dd - 1 > 0) ? (int)floor(sqrt(dd - 1)) : 0;

        vector<long long> dp(m + 1, 0), dp_next(m + 1, 0);
        auto &bottom = holds[n - 1];
        int k = bottom.size();
        vector<long long> diff(k + 1, 0);
        for (int i = 0; i < k; i++)
        {
            int x = bottom[i];
            int L = lower_bound(bottom.begin(), bottom.end(), x - d) - bottom.begin();
            int R_idx = upper_bound(bottom.begin(), bottom.end(), x + d) - bottom.begin() - 1;
            if (L <= R_idx)
            {
                diff[L] = (diff[L] + 1) % MOD;
                diff[R_idx + 1] = (diff[R_idx + 1] + MOD - 1) % MOD;
            }
        }
        long long cur = 0;
        for (int i = 0; i < k; i++)
        {
            cur = (cur + diff[i]) % MOD;
            dp[bottom[i]] = cur;
        }
        dp_next = dp;

        for (int row = n - 2; row >= 0; row--)
        {
            vector<long long> P(m + 1, 0);
            for (int j = 1; j <= m; j++)
            {
                P[j] = (P[j - 1] + dp_next[j]) % MOD;
            }
            auto &curRow = holds[row];
            int kRow = curRow.size();
            vector<long long> Tvals(kRow, 0);
            for (int i = 0; i < kRow; i++)
            {
                int x = curRow[i];
                int L_bound = max(1, x - R);
                int R_bound = min(m, x + R);
                Tvals[i] = (P[R_bound] - P[L_bound - 1] + MOD) % MOD;
            }
            vector<long long> diff2(kRow + 1, 0);
            for (int i = 0; i < kRow; i++)
            {
                int x = curRow[i];
                int L_idx = lower_bound(curRow.begin(), curRow.end(), x - d) - curRow.begin();
                int R_idx = upper_bound(curRow.begin(), curRow.end(), x + d) - curRow.begin() - 1;
                if (L_idx <= R_idx)
                {
                    diff2[L_idx] = (diff2[L_idx] + Tvals[i]) % MOD;
                    diff2[R_idx + 1] = (diff2[R_idx + 1] + MOD - Tvals[i]) % MOD;
                }
            }
            vector<long long> dp_current(m + 1, 0);
            cur = 0;
            for (int i = 0; i < kRow; i++)
            {
                cur = (cur + diff2[i]) % MOD;
                dp_current[curRow[i]] = cur;
            }
            dp_next = dp_current;
        }

        long long ans = 0;
        for (int col : holds[0])
            ans = (ans + dp_next[col]) % MOD;
        cout << ans << "\n";
    }
    return 0;
}
