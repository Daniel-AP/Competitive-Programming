#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    // We only care while Fibonacci still fits in signed 64-bit.
    const int MAX_I = 92; // F(92) fits, F(93) overflows signed long long

    int64 prev1 = 0, prev2 = 1;

    // Use long double everywhere for Binet side
    const long double sq = sqrtl(5.0L);
    const long double phi = (1.0L+sq) / 2.0L; // avoid constants that might be double-precision

    int bad = -1;

    // i=0 => 0, i=1 => 1. Your loop starts at i=2, keep that.
    for(int i = 2; i <= (int)min<long long>(n, MAX_I); i++) {
        // exact Fibonacci in 64-bit (safe up to 92)
        int64 cur = prev1+prev2;
        prev1 = prev2;
        prev2 = cur;

        // Binet with rounding (NOT truncation)
        long double x = (powl(phi, (long double)i)-powl(-phi, (long double)-i)) / sq;
        int64 binet = (int64) llroundl(x);

        if(cur != binet) {
            bad = i;
            break;
        }
    }

    cout << bad << "\n";
    return 0;
}
