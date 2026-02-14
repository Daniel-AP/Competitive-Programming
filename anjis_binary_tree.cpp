#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

int dfs(int u, vector<pair<int, int>>& adj, string& s) {

    int l = adj[u].first, r = adj[u].second;

    if(l != 0 && r != 0) {
        return min(dfs(l, adj, s)+(s[u-1]!='L'), dfs(r, adj, s)+(s[u-1]!='R'));
    } else if(l != 0) {
        return dfs(l, adj, s)+(s[u-1]!='L');
    } else if(r != 0) {
        return dfs(r, adj, s)+(s[u-1]!='R');
    } else {
        return 0;
    }

}

void solve() {

    int n; cin >> n;
    string s; cin >> s;

    vector<pair<int, int>> adj(n+1);

    for(int i = 1; i <= n; i++) {
        int l, r; cin >> l >> r;
        adj[i].first = l;
        adj[i].second = r;
    }

    cout << dfs(1, adj, s) << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}