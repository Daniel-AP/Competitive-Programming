#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

#define MOD 1000000007
// #define MOD 998244353

const int N = 200005;
int fact[N];

void pre() {

    fact[0] = 1;
    for(int i = 1; i < N; i++) fact[i] = fact[i-1]*i%MOD;

}

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

int inv(int a) {
    a %= MOD;
    return binpow(a, MOD-2);
}

int C(int n, int r) {
    if(r > n) return 0;
    return fact[n]*inv(fact[r])%MOD*inv(fact[n-r])%MOD;
}

void solve() {

    int n, k; cin >> n >> k;
    int cnt0 = 0, cnt1 = 0;

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        cnt0 += (x==0);
        cnt1 += (x==1);
    }

    int ans = 0;

    for(int i = 0; i <= k/2; i++) {
        ans += C(cnt0, i)*C(cnt1, k-i)%MOD;
        ans %= MOD;
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