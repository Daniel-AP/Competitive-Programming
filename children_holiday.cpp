#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int m, n; cin >> m >> n;

    vector<array<int, 3>> tzy(n);

    for(int i = 0; i < n; i++) {
        cin >> tzy[i][0] >> tzy[i][1] >> tzy[i][2];
    }

    int l = 0, r = 1e18, mid, ans = 0;

    while(l <= r) {

        mid = l+(r-l)/2;

        int cnt = 0;

        for(int i = 0; i < n; i++) {
            cnt += mid/(tzy[i][1]*tzy[i][0]+tzy[i][2])*tzy[i][1];
            cnt += min(tzy[i][1], mid%(tzy[i][1]*tzy[i][0]+tzy[i][2])/tzy[i][0]);
            cnt = min(cnt, m);
        }

        if(cnt >= m) {
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }

    }

    cout << ans << '\n';

    for(int i = 0; i < n; i++) {
        int b = ans/(tzy[i][1]*tzy[i][0]+tzy[i][2])*tzy[i][1]+min(tzy[i][1], ans%(tzy[i][1]*tzy[i][0]+tzy[i][2])/tzy[i][0]);
        b = min(b, m);
        m -= b;
        cout << b << ' ';
    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}