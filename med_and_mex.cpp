#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

// #define MOD 1000000007
#define MOD 998244353

const int N = 600000+5;

int factorial[N];

int binpow(int a, int b) {

    a %= MOD;

    int ans = 1;

    while(b) {
        if(b&1) ans = (ans*a)%MOD;
        a = (a*a)%MOD;
        b /= 2;
    }

    return ans;

}

int inv(int n) {

    n %= MOD;

    return binpow(n, MOD-2);

}

int comb(int n, int k) {

    if(k < 0 || k > n) return 0;

    return factorial[n]*inv(factorial[k])%MOD*inv(factorial[n-k])%MOD;

}

void pre() {

    factorial[0] = 1;
    for(int i = 1; i < N; i++) factorial[i] = (factorial[i-1]*i)%MOD;

}

void solve() {

    int n; cin >> n;

    vector<int> ans(n+1);

    for(int i = 2; i <= n && 2*(i-1) < n; i++) {
        ans[i] = comb(n-i-1, i-2)*factorial[2*(i-1)]%MOD*factorial[n-2*(i-1)]%MOD*(n-2*(i-1)+1)%MOD;
    }

    for(int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }

    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    pre();

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}