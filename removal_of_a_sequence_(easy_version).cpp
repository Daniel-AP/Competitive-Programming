#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int x, y, k; cin >> x >> y >> k;
    int l = k, r = 1e12, mid, ans;

    int n = 1e12, op = 0, q = 1e12;

    while(op < x) {
        n -= q/y;
        q -= q/y;
        op++;
    }

    if(n < k) return void(cout << -1 << '\n');

    while(l <= r) {

        mid = l+(r-l)/2;

        int cnt = 0, op = 0, q = mid-1;

        while(op < x) {
            cnt += q/y;
            q -= q/y;
            op++;
        }

        if(mid-cnt <= k) {
            ans = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }

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