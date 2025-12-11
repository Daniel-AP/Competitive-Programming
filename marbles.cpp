#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k; cin >> n >> k;

    int den = 1, num = 1, ans = 1;

    n -= k;
    n = n+k-1, k = k-1;

    for(int i = 1; i <= k; i++) {
        
        num = n-k+i;
        den = i;

        int g = __gcd(num, den);
        num /= g, den /= g;

        g = __gcd(ans, den);
        ans /= g, den /= g;

        ans *= num;

    }

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}