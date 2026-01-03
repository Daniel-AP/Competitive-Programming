#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int ans = 0;

    for(int i = 1; i < n; i += 2) {
        int s = a[i-1];
        if(i+1 < n) {
            s += a[i+1];
            if(s > a[i]) {
                int diff = s-a[i];
                ans += diff;
                int t = a[i+1];
                a[i+1] -= min(diff, a[i+1]);
                diff -= min(diff, t);
                a[i-1] -= diff;
            }
        } else {
            if(s > a[i]) {
                int diff = s-a[i];
                a[i-1] -= diff;
                ans += diff;
            }
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