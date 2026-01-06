#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int a, b; cin >> a >> b;

    int ans = 1;
    int cnt0 = 1, cnt1 = 0, cur = 2;

    for(int i = 2;; i++) {
        if(i%2 == 0) {
            cnt1 += cur;
        } else {
            cnt0 += cur;
        }
        if((a >= cnt0 && b >= cnt1) || (b >= cnt0 && a >= cnt1)) {
            ans++;
        } else {
            break;
        }
        cur *= 2;
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