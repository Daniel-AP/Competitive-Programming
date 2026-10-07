#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
#define MOD 998244353

const int N = 55;
vector<int> fact(N);

void pre() {
    fact[0] = 1;
    for(int i = 1; i < N; i++) fact[i] = fact[i-1]*i%MOD;
}

int binpow(int a, int b) {
    int ans = 1;
    while(b) {
        if(b&1) ans = (ans*a)%MOD;
        a = (a*a)%MOD;
        b /= 2;
    }
    return ans;
}

int inv(int a) {
    return binpow(a, MOD-2);
}

int comb(int n, int k) {
    if(k > n) return 0;
    if(n == k || k == 0) return 1;
    return fact[n]*inv(fact[n-k])%MOD*inv(fact[k])%MOD;
}

void solve() {

    int n; cin >> n;

    vector<int> a(n+1);
    for(int i = 0; i <= n; i++) cin >> a[i];

    int mx = *max_element(a.begin()+1, a.end());
    int cnt = count(a.begin()+1, a.end(), mx);

    int a0 = a[0];
    for(int i = 1; i <= n; i++) a0 -= max(mx-1-a[i], 0LL);

    if(a0 < 0) return void(cout << 0 << '\n');

    int ans = 0;

    for(int i = cnt; i <= n; i++) {
        if(i-cnt > a0) break;
        ans = (ans+comb(i-1, cnt-1)*fact[cnt]%MOD*fact[n-cnt]%MOD)%MOD;
    }

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    pre();

    while(t--) solve();

    return 0;

}