#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

#define MOD 1000000007
// #define MOD 998244353

int binpow(int a, int b, int m) {

    a %= m;

    int ans = 1;

    while(b) {
        if(b&1) ans *= a, ans %= m;
        a *= a, a %= m;
        b >>= 1;
    }

    return ans;

}

int inv(int a, int m) {

    a %= m;
    return binpow(a, m-2, m);

}

void solve() {

    int n; cin >> n;

    vector<pair<int, int>> p(n);
    for(int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;

    int d1 = 1;

    for(int i = 0; i < n; i++) {
        d1 *= p[i].second+1;
        d1 %= MOD;
    }

    bool square = true, halved = false;
    
    for(int i = 0; i < n; i++) {
        if(p[i].second&1) square = false;
    }

    int d2 = 1;

    for(int i = 0; i < n; i++) {
        if(!square && !halved && (p[i].second&1)) {
            d2 *= (p[i].second+1)/2;
            halved = true;
        } else {
            d2 *= p[i].second+1;
        }
        d2 %= MOD-1;
    }

    int x = 1;

    for(int i = 0; i < n; i++) {
        if(square) {
            x *= binpow(p[i].first, p[i].second/2, MOD);
        } else {
            x *= binpow(p[i].first, p[i].second, MOD);
        }
        x %= MOD;
    }

    int pr = binpow(x, d2, MOD);

    int s = 1;

    for(int i = 0; i < n; i++) {
        s *= (binpow(p[i].first, p[i].second+1, MOD)-1)%MOD, s %= MOD;
        s *= inv(p[i].first-1, MOD), s %= MOD;
    }

    cout << d1 << ' ' << s << ' ' << pr;
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}