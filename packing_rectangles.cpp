#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int w, h, n; cin >> w >> h >> n;
    int l = 1, r = 1e18+5, ans, mid;

    while(l <= r) {

        mid = l+(r-l)/2;
        int m = mid/w;

        if(m == 0) {
            l = mid+1;
            continue;
        }

        int need = (n+m-1)/m;

        if(need <= mid/h) {
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
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