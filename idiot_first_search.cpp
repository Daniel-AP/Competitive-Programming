#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

#define MOD 1000000007
// #define MOD 998244353

int dfs1(int u, vector<pair<int, int>>& children, vector<int>& memo) {

    if(memo[u] != -1) return memo[u];
    if(children[u].first == 0 && children[u].second == 0) return 1;
    if(children[u].second == 0) {
        memo[u] = dfs1(children[u].first, children, memo)+1;
        memo[u] %= MOD;
        return memo[u];
    }

    memo[u] = dfs1(children[u].first, children, memo)+dfs1(children[u].second, children, memo)+3;
    memo[u] %= MOD;

    return memo[u];

}

void dfs2(int u, int cur, vector<int>& ans, vector<pair<int, int>>& children, vector<int>& memo) {

    ans[u] = cur;

    auto [l, r] = children[u];

    if(l != 0) dfs2(l, (cur+dfs1(l, children, memo))%MOD, ans, children, memo);
    if(r != 0) dfs2(r, (cur+dfs1(r, children, memo))%MOD, ans, children, memo);

}

void solve() {

    int n; cin >> n;

    vector<pair<int, int>> children(n+1);
    vector<int> memo(n+1, -1);

    for(int i = 1; i <= n; i++) {
        int l, r; cin >> l >> r;
        children[i].first = l, children[i].second = r;
    }

    children[0] = {1, 0};

    dfs1(0, children, memo);

    vector<int> ans(n+1);

    dfs2(0, 0, ans, children, memo);

    for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
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