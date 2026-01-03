#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
#define MOD 998244353

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

void solve() {

    int n; cin >> n;
    string s; cin >> s;

    int ans = 0, cur = 1;

    for(int i = 1; i < n; i++) {
        if(s[i] != s[i-1]) {
            ans += binpow(2, cur-1);
            cur = 1;
        } else {
            ans += binpow(2, cur-1);
            cur++;
        }
        ans %= MOD;
    }

    ans += binpow(2, cur-1);

    cout << ans%MOD << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}