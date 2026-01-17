#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> u(n), s(n);

    for(int i = 0; i < n; i++) cin >> u[i];
    for(int i = 0; i < n; i++) cin >> s[i];

    map<int, vector<int>> us;

    for(int i = 0; i < n; i++) us[u[i]].push_back(s[i]);
    for(auto& [k, v]: us) sort(all(v));

    vector<int> ans(n);

    for(auto& [k, v]: us) {

        int m = v.size();
        
        vector<int> px(m+1);
        partial_sum(all(v), px.begin()+1);

        for(int i = 0; i < m; i++) {
            ans[i] += (px[m]-px[m%(i+1)]);
        }

    }

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