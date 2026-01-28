#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

int n, m;

vector<double> memo(100001, INF);
vector<vector<pair<int, int>>> adj(100001, vector<pair<int, int>>());

double dfs(int u, double x) {

    if(memo[u] != INF) return memo[u];
    if(u == n) return 0;

    for(auto [v, c]: adj[u]) {
        memo[u] = min(memo[u], c-x+dfs(v, x));
    }

    return memo[u];

}

void build(int u, double x, vector<int>& ans) {

    ans.push_back(u);

    if(u == n) return;

    for(auto [v, c]: adj[u]) {
        if(memo[u] == c-x+dfs(v, x)) {
            build(v, x, ans);
            break;
        }
    }

}

void solve() {

    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({ b, c });
    }

    double l = 0, r = 100, mid, ans;

    for(int i = 0; i < 100; i++) {

        mid = l+(r-l)/2;
        fill(all(memo), INF);

        if(dfs(1, mid) <= 0) {
            ans = mid;
            r = mid;
        } else {
            l = mid;
        }

    }

    fill(all(memo), INF);

    dfs(1, ans);
    
    vector<int> path;

    build(1, ans, path);

    cout << path.size()-1 << '\n';
    for(int x: path) cout << x << ' ';
    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}