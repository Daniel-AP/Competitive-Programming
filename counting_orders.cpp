#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

#define MOD 1000000007
// #define MOD 998244353

const int N = 200000;

int fact[N+1];
int ifact[N+1];

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

void pre() {

    fact[0] = 1;
    for(int i = 1; i <= N; i++) fact[i] = i*fact[i-1]%MOD;

    for(int i = 0; i <= N; i++) ifact[i] = binpow(fact[i], MOD-2);

}

int P(int n, int r) {
    if(r > n) return 0;
    return fact[n]*ifact[n-r]%MOD;
}

void solve() {

    int n; cin >> n;

    vector<int> a(n), b(n);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    
    sort(all(a));

    vector<int> need(n);

    for(int i = 0; i < n; i++) {
        int j = upper_bound(all(a), b[i])-a.begin();
        if(j == n) return void(cout << 0 << '\n');
        need[j]++;
    }

    for(int i = 0; i < n; i++) {
        if(need[i] > n-i) return void(cout << 0 << '\n');
    }

    int has = 0, ans = 1;

    for(int i = n-1; i >= 0; i--) {
        has++;
        ans *= P(has, need[i]);
        ans %= MOD;
        has -= need[i];
    }

    cout << ans << '\n';
    
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