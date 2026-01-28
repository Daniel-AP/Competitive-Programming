#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";
#define MOD 998244353

int factorial[1000001];

int binpow(int b, int e) {

    int res = 1;

    while(e > 0) {
        if(e&1) res = (res*b)%MOD;
        b = (b*b)%MOD;
        e >>= 1;
    }

    return res;

}

void precomp_factorials() {

    factorial[0] = 1;

    for(int i = 1; i <= 1000000; i++) {
        factorial[i] = (factorial[i-1]*i)%MOD;
    }

}

int inv(int n) {

    return binpow(n, MOD-2);

}

int comb(int n, int k) {

    if(k > n) return 0;

    return factorial[n]*inv(factorial[k])%MOD*inv(factorial[n-k])%MOD;

}

void solve() {

    precomp_factorials();

    int q; cin >> q;

    for(int i = 0; i < q; i++) {
        int n, k; cin >> n >> k;
        int ans = 0;
        for(int j = 1; j <= n; j++) ans = (ans+j*comb(n-j, k-1))%MOD;
        cout << ans << '\n';
    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; t = 1;

    while(t--) solve();

    return 0;

}