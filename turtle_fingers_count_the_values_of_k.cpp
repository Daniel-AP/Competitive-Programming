#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

bool can(int m, int a, int b) {

    for(int i = 1; i <= m; i *= a) {
        for(int j = 1; j <= m; j *= b) {
            if(i*j == m) return true;
        }
    }

    return false;

}

void solve() {

    int a, b, l; cin >> a >> b >> l;

    int ans = 0;

    for(int i = 1; i*i <= l; i++) {
        if(l%i != 0) continue;
        ans += can(l/i, a, b);
        if(l/i != i) ans += can(i, a, b);
    }

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}