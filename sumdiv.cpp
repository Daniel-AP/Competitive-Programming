#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

#define MOD 1000000007
// #define MOD 998244353

int binpow(int a, __uint128_t b) {

    a %= MOD;

    int ans = 1; 

    while(b) {
        if(b&1) ans *= a, ans %= MOD;
        a *= a, a %= MOD;
        b >>= 1;
    }

    return ans;

}

int inv(int n) {
	n %= MOD;
    return binpow(n, MOD-2);
}

void solve() {

    int a, b; cin >> a >> b;
    int ans = 1;

    map<int, int> f;

    for(int i = 2; i*i <= a; i++) {
        while(a%i == 0) f[i]++, a /= i;
    }

    if(a != 1) f[a]++;

    for(auto [k, v]: f) {
        
		__uint128_t e = (__uint128_t)v*(__uint128_t)b+1;
		
		if(k%MOD == 1) {
			ans *= e%MOD;
		} else {
			ans *= (binpow(k, e)-1)%MOD;
			ans %= MOD;
			ans *= inv(k-1);
		}
		
		ans %= MOD;
		
    }

    cout << ans;
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("sumdiv.in", "r", stdin);
    freopen("sumdiv.out", "w", stdout);

    int t = 1;

    while(t--) solve();

    return 0;

}