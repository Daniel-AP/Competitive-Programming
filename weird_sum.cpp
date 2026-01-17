#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, m; cin >> n >> m;

    map<int, vector<int>> r, c;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int x; cin >> x;
            r[x].push_back(i+1);
            c[x].push_back(j+1);
        }
    }

    for(auto& [k, v]: r) sort(all(v));
    for(auto& [k, v]: c) sort(all(v));

    int ans = 0;

    for(auto& [k, v]: r) {
        int s = 0, cur = 0, l = v.size();
        for(int x: v) s += x;
        for(int i = 0; i < l; i++) {
            cur += v[i];
            ans += s-cur-v[i]*(l-i-1);
        }
    }
    for(auto& [k, v]: c) {
        int s = 0, cur = 0, l = v.size();
        for(int x: v) s += x;
        for(int i = 0; i < l; i++) {
            cur += v[i];
            ans += s-cur-v[i]*(l-i-1);
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