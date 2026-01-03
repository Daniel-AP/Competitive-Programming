#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n),end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int m; cin >> m;

    vector<int> p(m);
    for(int i = 0; i < m; i++) cin >> p[i];

    int ans = 0;

    for(int i = 2; i <= m; i *= 2) {
        for(int j = 0; j < m; j += i) {
            int k1 = j+i/2-1, k2 = j+i-1;
            if(abs(p[k1]-p[k2]) != i/2) return void(cout << -1 << '\n');
            if(p[k1] > p[k2]) {
                ans++;
                swap(p[k1], p[k2]);
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