#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];

    vector<array<int, 32>> px(n+1);
    
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 32; j++) {
            px[i][j] = px[i-1][j]+((a[i]&(1LL<<j))==0);
        }
    }

    int q; cin >> q;

    while(q--) {

        int l, k; cin >> l >> k;
        int lb = l, rb = n, mid, ans = -1;

        while(lb <= rb) {
            mid = lb+(rb-lb)/2;
            int cur = 0;
            for(int j = 0; j < 32; j++) {
                if(px[mid][j]-px[l-1][j] != 0) continue;
                cur |= (1LL<<j);
            }
            if(cur >= k) {
                ans = mid;
                lb = mid+1;
            } else {
                rb = mid-1;
            }
        }

        cout << ans << ' ';

    }

    cout << '\n';

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}