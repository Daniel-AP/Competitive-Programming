#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

map<int, int> memo;

int dfs(int u, string& s, vector<vector<int>>& children) {

    if(memo.find(u) != memo.end()) return memo[u];

    memo[u] = (s[u-1] == 'W' ? 1 : -1);
    for(int v: children[u]) {
        memo[u] += dfs(v, s, children);
    }

    return memo[u];

}

void solve() {

    int n; cin >> n;

    vector<int> a(n-1);
    for(int i = 0; i < n-1; i++) cin >> a[i];

    string s; cin >> s;

    memo.clear();

    vector<vector<int>> children(n+1, vector<int>());

    for(int i = 0; i < n-1; i++) {
        children[a[i]].push_back(i+2);
    }

    int ans = 0;

    for(int i = 1; i <= n; i++) {
        ans += (dfs(i, s, children) == 0);
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