#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

// #define MOD 1000000007
// #define MOD 998244353

int comb(int n, int k) {

    if(k < 0 || k > n) return 0;

    int num = 1, den = 1;

    for(int i = 1; i <= k; i++) {
        num *= (n-k+i);
        den *= i;
    }

    return num/den;

}

void solve() {

    int n, k; cin >> n >> k;
    int ans = 1;

    if(k >= 2) ans += comb(n, 2);
    if(k >= 3) ans += comb(n, 3)*2;
    if(k >= 4) ans += comb(n, 4)*9;

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}