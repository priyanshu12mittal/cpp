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

// Use 64-bit integer type for n, k.
// (If your limits require more, consider using __int128 where needed.)

const ll MOD = 1000000007;

// Modular arithmetic helpers
inline ll modAdd(ll a, ll b) { return ((a % MOD) + (b % MOD)) % MOD; }
inline ll modMul(ll a, ll b) { return ((a % MOD) * (b % MOD)) % MOD; }

// Compute modular exponentiation
ll modExp(ll base, ll exp)
{
    ll result = 1 % MOD;
    base %= MOD;
    while (exp)
    {
        if (exp & 1)
            result = modMul(result, base);
        base = modMul(base, base);
        exp >>= 1;
    }
    return result;
}

// Compute modular inverse using Fermat’s little theorem (MOD is prime)
ll modInv(ll a)
{
    return modExp(a, MOD - 2);
}

// Precomputed inverses for 2 and 6 (used in summation formulas)
const ll inv2 = modInv(2);
const ll inv6 = modInv(6);

// Sum of integers from L to R modulo MOD
ll sumRange(ll L, ll R)
{
    // sum_{i=L}^{R} = (R*(R+1) - (L-1)*L)/2
    ll sR = modMul(R, R + 1);
    ll sL = modMul(L - 1, L);
    ll diff = ((sR - sL) % MOD + MOD) % MOD;
    return modMul(diff, inv2);
}

// Sum of squares from L to R modulo MOD
ll sumSquares(ll L, ll R)
{
    // sum_{i=1}^{n} i^2 = n(n+1)(2n+1)/6.
    auto sum1 = [&](ll n) -> ll
    {
        return modMul(modMul(n, n + 1), modMul(2 * n + 1, inv6));
    };
    ll sR = sum1(R);
    ll sL = sum1(L - 1);
    return ((sR - sL) % MOD + MOD) % MOD;
}

// Sum of cubes from L to R modulo MOD
ll sumCubes(ll L, ll R)
{
    // sum_{i=1}^{n} i^3 = (n(n+1)/2)^2.
    auto sum1 = [&](ll n) -> ll
    {
        ll s = modMul(n, n + 1);
        s = modMul(s, inv2);
        return modMul(s, s);
    };
    ll sR = sum1(R);
    ll sL = sum1(L - 1);
    return ((sR - sL) % MOD + MOD) % MOD;
}

// Binary search: returns floor( n^(1/r) )
// (We use __int128 for safety.)
ll kthRoot(ll n, int r)
{
    ll lo = 1, hi = (ll)1e9; // adjust hi if needed
    ll ans = 1;
    while (lo <= hi)
    {
        ll mid = (lo + hi) / 2;
        __int128 p = 1;
        for (int i = 0; i < r; i++)
        {
            p *= mid;
            if (p > n)
                break;
        }
        if (p <= n)
        {
            ans = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    return ans;
}

// When the digit count L is small, we can simulate the base conversion.
ll revBySimulation(ll n, ll p)
{
    vector<ll> digits;
    ll temp = n;
    while (temp)
    {
        digits.push_back(temp % p);
        temp /= p;
    }
    // Reverse the digit vector and convert back to a number modulo MOD.
    ll res = 0;
    for (int i = digits.size() - 1; i >= 0; i--)
    {
        res = (modMul(res, p) + digits[i]) % MOD;
    }
    return res;
}

void solve()
{
    ll n, k;
    cin >> n >> k;

    ll ans = 0;

    // Notice: if p > n then n has only 1 digit in base p,
    // so rev(n, p) = n.
    if (k > n)
    {
        ll count = (k - n);
        ans = modAdd(ans, modMul(count, n % MOD));
    }

    // For bases p <= min(k, n), n has >=2 digits.
    ll limit = min(k, n);

    // We group by digit-length L.
    // L = 1 is handled above. Now consider L >= 2.
    // For a fixed digit count L, the condition is:
    //     p^(L-1) <= n < p^L.
    // Equivalently, p is in ( floor(n^(1/L)) , floor(n^(1/(L-1)) ].
    for (int L = 2;; L++)
    {
        ll lowP = kthRoot(n, L) + 1;  // smallest p with n < p^L
        ll highP = kthRoot(n, L - 1); // largest p with p^(L-1) <= n
        if (lowP < 2)
            lowP = 2;
        if (lowP > highP)
            break; // no p gives this digit–length
        if (lowP > limit)
            break;
        highP = min(highP, limit);

        // We now sum rev(n, p) over p in [lowP, highP].
        // For L = 2 and 3 we derive closed–form expressions.
        if (L == 2)
        {
            // For L = 2, write n = a1*p + a0 with a1 = floor(n/p), a0 = n - p*a1.
            // Then rev(n,p) = a0*p + a1 = n*p - (p^2 - 1)*floor(n/p).
            ll pcur = lowP;
            while (pcur <= highP)
            {
                ll q = n / pcur; // floor(n/p) (it stays constant for an interval)
                // The standard grouping: p in [pcur, next] all have the same q.
                ll nextP = n / q; // largest p with floor(n/p)==q.
                if (nextP > highP)
                    nextP = highP;

                // Sum over p in [pcur, nextP] of n*p
                ll S1 = sumRange(pcur, nextP);
                ll term1 = modMul(n % MOD, S1);
                // Sum over p in [pcur, nextP] of (p^2 - 1)
                ll S2 = sumSquares(pcur, nextP);
                ll count = (nextP - pcur + 1) % MOD;
                ll term2 = modAdd(S2, (MOD - count)); // (p^2-1) summed = S2 - count.
                term2 = modMul(q % MOD, term2);

                ll segSum = (term1 - term2) % MOD;
                if (segSum < 0)
                    segSum += MOD;
                ans = modAdd(ans, segSum);

                pcur = nextP + 1;
            }
        }
        else if (L == 3)
        {
            // For L = 3, write n = a2*p^2 + a1*p + a0, where:
            //   a2 = floor(n / p^2)
            //   a1 = floor(n / p) - p * floor(n / p^2)
            //   a0 = n - p * floor(n / p)
            // Then rev(n,p) = a0*p^2 + a1*p + a2
            //   = n*p^2 - p^3*floor(n/p) + p*floor(n/p) - p^2*floor(n/p^2) + floor(n/p^2)
            //   = n*p^2 + floor(n/p)*(p - p^3) + floor(n/p^2)*(1 - p^2).
            ll pcur = lowP;
            while (pcur <= highP)
            {
                ll f = n / pcur;          // floor(n/p)
                ll g = n / (pcur * pcur); // floor(n/p^2)
                // In an interval where f and g remain constant,
                // the next change for f is at p = n/f, and for g at about sqrt(n/g).
                ll next1 = n / f;
                // For g, solve: floor(n / (p^2)) = g  =>  p^2 <= n/g, so p <= floor(sqrt(n/g)).
                ll next2 = (ll)floor(sqrt((long double)n / (g ? g : 1)));
                ll nextP = min({highP, next1, next2});

                ll cnt = (nextP - pcur + 1) % MOD;
                ll S1 = sumRange(pcur, nextP);   // sum of p
                ll S2 = sumSquares(pcur, nextP); // sum of p^2
                ll S3 = sumCubes(pcur, nextP);   // sum of p^3

                ll termA = modMul(n % MOD, S2);                        // n * sum(p^2)
                ll termB = modMul((f % MOD), ((S1 - S3) % MOD + MOD)); // f*(sum(p) - sum(p^3))
                termB %= MOD;
                ll termC = modMul(g % MOD, ((cnt - S2) % MOD + MOD)); // g*(count - sum(p^2))
                termC %= MOD;

                ll segSum = (termA + termB + termC) % MOD;
                ans = modAdd(ans, segSum);

                pcur = nextP + 1;
            }
        }
        else
        {
            // For L >= 4, the interval [lowP, highP] is short. We compute rev(n, p)
            // by simulating the base conversion.
            for (ll p = lowP; p <= highP; p++)
            {
                ll val = revBySimulation(n, p);
                ans = modAdd(ans, val);
            }
        }
    }

    cout << ans % MOD << "\n";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
