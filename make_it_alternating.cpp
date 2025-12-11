#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
#define MOD 998244353

const int N = 200000;
int factorial[N+1];

void pre() {

    factorial[0] = 1;
    for(int i = 1; i < N; i++) factorial[i] = factorial[i-1]*i%MOD;

}

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

int inv(int a) {

    a %= MOD;

    return binpow(a, MOD-2);

}

int comb(int n, int k) {

    if(k > n) return 0;

    return factorial[n]*inv(factorial[k])%MOD*inv(factorial[n-k])%MOD;

}

void solve() {

    string s; cin >> s;

    int n = s.length();
    int ops = 0, cnt = 1;

    vector<int> movs;

    for(int i = 1; i < n; i++) {
        if(s[i] != s[i-1]) {
            ops += cnt-1;
            movs.push_back(cnt);
            cnt = 1;
        } else {
            cnt++;
        }
    }

    ops += cnt-1;
    movs.push_back(cnt);

    int ways = factorial[ops];

    for(int x: movs) {
        ways *= comb(x, x-1);
        ways %= MOD;
    }

    cout << ops << ' ' << ways << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    pre();

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}