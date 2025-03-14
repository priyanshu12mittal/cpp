#include <iostream>
using namespace std;

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
        if (n == 3)
        {
            cout << "! 1 2 3" << "\n";
            cout.flush();
            continue;
        }

        int a = 1, b = 2, c = 3;
        int queryCount = 0;
        while (true)
        {
            cout << "? " << a << " " << b << " " << c << "\n";
            cout.flush();
            queryCount++;
            int response;
            cin >> response;
            if (response == -1)
                return 0;

            if (response == 0)
            {
                cout << "! " << a << " " << b << " " << c << "\n";
                cout.flush();
                break;
            }
            int p = response;
            bool foundEmptyCandidate = false;
            int cand[3][3] = {{a, b, p}, {a, c, p}, {b, c, p}};
            for (int i = 0; i < 3; i++)
            {
                int x = cand[i][0], y = cand[i][1], z = cand[i][2];
                cout << "? " << x << " " << y << " " << z << "\n";
                cout.flush();
                queryCount++;
                int resCandidate;
                cin >> resCandidate;
                if (resCandidate == -1)
                    return 0;
                if (resCandidate == 0)
                {
                    a = x;
                    b = y;
                    c = z;
                    foundEmptyCandidate = true;
                    break;
                }
            }
            if (!foundEmptyCandidate)
            {
                c = p;
            }
            if (queryCount > 75)
                break;
        }
    }
    return 0;
}
