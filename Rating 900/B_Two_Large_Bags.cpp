#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Given a nonnegative difference d, return the minimum number of coins (1,2,5)
// needed to represent d.
int coinChange(int d)
{
    int moves = 0;
    moves += d / 5;
    d %= 5;
    moves += d / 2;
    d %= 2;
    moves += d;
    return moves;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        int m = 1e9;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            m = min(m, arr[i]);
        }

        // Try five possible bases: m, m-1, ..., m-4.
        int best = 1e9;
        for (int base = m; base >= m - 4; base--)
        {
            int sumMoves = 0;
            for (int a : arr)
            {
                int d = a - base;
                // d should be nonnegative because base is at most m.
                sumMoves += coinChange(d);
            }
            best = min(best, sumMoves);
        }

        // In our transformation, a valid sequence of moves exists if and only if
        // the minimum number of operations (over all five bases) is even.
        cout << (best % 2 == 0 ? "Yes" : "No") << "\n";
    }

    return 0;
}
