#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

#define MOD 1000000007
// #define MOD 998244353

const int N = 500000;

int fact[N+1], ifact[N+1];

int binpow(int a, int b) {

    a %= MOD;

    int ans = 1;

    while(b) {
        if(b%2) ans = (ans*a)%MOD;
        a = (a*a)%MOD;
        b /= 2;
    }

    return ans;

}

int C(int n, int k) {

    if(k > n) return 0;

    return fact[n]*ifact[k]%MOD*ifact[n-k]%MOD;

}

void pre() {

    fact[0] = 1;
    for(int i = 1; i <= N; i++) fact[i] = i*fact[i-1]%MOD;
    for(int i = 0; i <= N; i++) ifact[i] = binpow(fact[i], MOD-2);

}

void solve() {

    int n; cin >> n;

    cout << C(2*n-1, n-1) << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    pre();

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}