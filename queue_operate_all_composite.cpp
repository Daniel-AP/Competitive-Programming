#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

// #define MOD 1000000007
#define MOD 998244353

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

int inv(int a) {
    a %= MOD;
    return binpow(a, MOD-2);
}

void solve() {

    int t; cin >> t;
    int s = 0, p = 1;

    queue<pair<int, int>> q;

    while(t--) {

        int op; cin >> op;

        switch(op) {

            case 0: {
                int a, b; cin >> a >> b;
                q.push({ a, b });
                s = a*s%MOD+b, s %= MOD;
                p *= a, p %= MOD;
                break;
            }
            case 1: {
                auto [a, b] = q.front();
                q.pop();
                int f = p*inv(a)%MOD*b%MOD;
                s -= f, s %= MOD;
                p *= inv(a), p %= MOD;
                break;
            }
            case 2: {
                int x; cin >> x;
                cout << (s+p*x%MOD)%MOD << '\n';
                break;
            }
        }

    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}