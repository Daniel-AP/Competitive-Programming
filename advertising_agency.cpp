#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

#define MOD 1000000007
// #define MOD 998244353

const int N = 1005;
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
    return fact[n]*inv(fact[n-k])%MOD*inv(fact[k])%MOD;
}

void solve() {

    int n, k; cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> cnt(n+1);
    for(int i = 0; i < n; i++) cnt[a[i]]++;

    sort(all(a));

    set<int> un;
    vector<int> need(n+1);

    for(int i = 1; i <= k; i++) {
        un.insert(a[n-i]);
        need[a[n-i]]++;
    }

    int ans = 1;

    for(int x: un) {
        ans *= comb(cnt[x], need[x]);
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