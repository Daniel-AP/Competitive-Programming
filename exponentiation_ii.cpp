#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

#define MOD 1000000007
// #define MOD 119*(1LL<<23)+1

int binpow(int a, int b, int m = MOD) {

    a %= m;

    int ans = 1;

    while(b) {
        if(b&1) ans *= a, ans %= m;
        a *= a, a %= m;
        b >>= 1;
    }

    return ans;

}

void solve() {

    int n; cin >> n;

    for(int i = 0; i < n; i++) {

        int a, b, c; cin >> a >> b >> c;

        cout << binpow(a, binpow(b, c, MOD-1)) << '\n';

    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; t = 1;

    while(t--) solve();

    return 0;

}