#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    long double c; cin >> c;
    long double l = 1e-6, r = c, mid, ans;

    for(int it = 0; it < 1000; it++) {
        mid = l+(r-l)/2;
        if(mid*mid+sqrtl(mid) >= c) {
            ans = mid;
            r = mid;
        } else {
            l = mid;
        }
    }

    cout << fixed << setprecision(9) << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}