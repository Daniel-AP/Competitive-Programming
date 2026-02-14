#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, x, y; cin >> n >> x >> y;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int s = 0;
    for(int i = 0; i < n; i++) s += a[i]/x*y;

    int ans = 0;

    for(int i = 0; i < n; i++) {
        ans = max(ans, s-a[i]/x*y+a[i]);
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