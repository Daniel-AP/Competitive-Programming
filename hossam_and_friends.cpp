#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, m; cin >> n >> m;
    int ans = n*(n+1)/2;

    map<int, int> mp;

    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        mp[max(x, y)] = max(mp[max(x, y)], min(x, y));
    }

    int prev = 0;
    
    for(auto [k, v]: mp) {
        ans -= max(v-prev, 0LL)*(n-k+1);
        prev = max(prev, v);
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