#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

#define MOD 1000000007
// #define MOD 998244353

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

void solve() {

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> px(n+1);
    partial_sum(a.begin(), a.end(), px.begin()+1);

    int num = 0;
    for(int i = 0; i < n; i++) {
        num += a[i]*((px[n]-px[i+1])%MOD);
        num %= MOD;
    }

    int den = n*(n-1)/2%MOD;

    cout << (num*inv(den))%MOD << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}