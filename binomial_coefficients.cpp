#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

#define MOD 1000000007
// #define MOD 998244353

int N = 1e6;

vector<int> factorial(N+1);

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

void pre() {

    factorial[0] = 1;
    for(int i = 1; i <= N; i++) factorial[i] = (factorial[i-1]*i)%MOD;

}

void solve() {

    int n; cin >> n;

    while(n--) {

        int a, b; cin >> a >> b;

        cout << factorial[a]*inv(factorial[b])%MOD*inv(factorial[a-b])%MOD << '\n';

    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    pre();

    while(t--) solve();

    return 0;

}