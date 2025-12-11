#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

#define MOD 1000000007
// #define MOD 998244353

int N = 1e6;

vector<int> invs(N+1), facts(N+1);

int binpow(int a, int b) {

    a %= MOD;

    int ans = 1;

    while(b) {
        if(b&1) ans *= a, ans %= MOD;
        a *= a, a %= MOD;
        b >>= 1;
    }

    return ans;

}

void pre() {

    // general form

    invs[1] = 1;
    for(int i = 2; i <= N; i++) {
        invs[i] = (MOD-(MOD/i)*invs[MOD%i]%MOD)%MOD;
    }

    // factorials
    
    facts[0] = 1;
    for(int i = 1; i <= N; i++) facts[i] = (facts[i-1]*i)%MOD;

    invs[1] = 0;
    invs[N] = binpow(N, MOD-2);

    for(int i = N; i >= 1; i--) {
        invs[i-1] = invs[i]*i%MOD;
    }

}

void solve() {

    
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}