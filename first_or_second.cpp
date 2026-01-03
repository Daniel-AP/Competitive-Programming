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

    vector<int> px(n+1);
    partial_sum(a.begin(), a.end(), px.begin()+1);

    vector<int> b(n+1);
    b[1] = 0;
    
    int mx = 2*a[0];

    for(int i = 2; i <= n; i++) {
        b[i] = mx-px[i-1];
        mx = max(mx, b[i]+a[i-1]+px[i]);
    }

    int ans = -INF;

    for(int i = 1; i <= n; i++) {
        ans = max(ans, b[i]-(px[n]-px[i]));
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