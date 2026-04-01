#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int l, g; cin >> l >> g;
    int ans = 0;

    for(int i = 0; i < g; i++) {
        int p, d; cin >> p >> d;
        if(d == 0) {
            ans = max(ans, p);
        } else {
            ans = max(ans, l-p);
        }
    }

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}