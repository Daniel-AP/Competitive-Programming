#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int h, n; cin >> h >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> c(n);
    for(int i = 0; i < n; i++) cin >> c[i];

    int l = 1, r = 1e12, mid, ans = 1;

    while(l <= r) {
        mid = l+(r-l)/2;
        int dam = 0;
        for(int i = 0; i < n; i++) {
            dam += a[i]*((mid-1)/c[i]+1);
            dam = min(dam, h);
        }
        if(dam >= h) {
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
    cin >> t;

    while(t--) solve();

    return 0;

}