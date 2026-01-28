#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

#define MOD 1000000007
// #define MOD 998244353

const int N = 4*1e5;

int factorial[N];

void pre() {

    factorial[0] = 1;
    for(int i = 1; i < N; i++) factorial[i] = (factorial[i-1]*i)%MOD;

}

int binpow(int a, int b) {

    a %= MOD;

    int ans = 1;

    while(b) {
        if(b&1) ans = (ans*a)%MOD;
        a = (a*a)%MOD;
        b >>= 1;
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

void solve() {

    int n, m, k; cin >> n >> m >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    int ans = 0;

    for(int i = 0; i < n; i++) {

        int r = upper_bound(a.begin(), a.end(), a[i]+k)-a.begin()-1;

        ans = (ans+comb(r-i, m-1))%MOD;

    }

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    pre();

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}