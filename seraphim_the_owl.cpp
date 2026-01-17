#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, m; cin >> n >> m;

    vector<int> a(n), b(n);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    vector<int> mn(n);
    for(int i = 0; i < n; i++) mn[i] = min(a[i], b[i]);

    int s = 0;
    for(int i = m; i < n; i++) s += mn[i];

    int ans = INF;

    for(int i = m-1; i >= 0; i--) {
        ans = min(ans, a[i]+s);
        s += mn[i];
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