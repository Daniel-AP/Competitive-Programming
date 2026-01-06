#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int m; cin >> m;

    map<int, int> mp;

    for(int i = 0; i < m; i++) {
        int n; cin >> n;
        for(int j = 0; j < n; j++) {
            int x; cin >> x;
            mp[x] = i;
        }
    }

    vector<int> ans(m, -1);

    for(auto [k, v]: mp) {
        ans[v] = k;
    }

    if(find(all(ans), -1) != ans.end()) return void(cout << -1 << '\n');

    for(int x: ans) cout << x << ' ';
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