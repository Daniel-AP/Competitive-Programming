#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

// #define MOD 1000000007
#define MOD 998244353

int binpow(int b, int e) {

    int res = 1;

    while(e > 0) {
        if(e&1) res = (res*b)%MOD;
        b = (b*b)%MOD;
        e >>= 1;
    }

    return res;

}

int inv(int n) {

    return binpow(n, MOD-2);

}

void solve() {

    int n; cin >> n;
    int den = n*n, num = 0, y = 1;

    den %= MOD;

    vector<int> cnt(1e6+1), ks(n);
    vector<vector<int>> a(n, vector<int>());

    for(int i = 0; i < n; i++) {

        cin >> ks[i];

        den *= ks[i];
        den %= MOD;
        y *= ks[i];
        y %= MOD;

        a[i].resize(ks[i]);

        for(int j = 0; j < ks[i]; j++) {
            cin >> a[i][j];
            cnt[a[i][j]]++;
        }

    }

    for(int i = 0; i < n; i++) {

        int s = 0;
        for(int p: a[i]) s += cnt[p], s %= MOD;

        num += s*y%MOD*inv(ks[i])%MOD;
        num %= MOD;

    }

    cout << num*inv(den)%MOD << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; t = 1;

    while(t--) solve();

    return 0;

}