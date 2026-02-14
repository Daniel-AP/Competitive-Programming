#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

struct DSU {
    vector<int> p, r;
    int n;

    DSU(int n) : n(n), p(n), r(n) {
        iota(all(p), 0);
    }

    int find(int a) {
        return p[a] == a ? a : (p[a] = find(p[a]));
    }

    bool join(int a, int b) {
        a = find(a), b = find(b);
        if(a == b) return 0;
        if(r[a] < r[b]) swap(a, b);
        p[b] = a;
        if(r[a] == r[b]) r[a]++;
        return 1;
    }
};

void solve() {

    int n, m1, m2; cin >> n >> m1 >> m2;

    vector<pair<int, int>> edg1(m1), edg2(m2);

    for(int i = 0; i < m1; i++) {
        int u, v; cin >> u >> v;
        edg1[i] = {u, v};
    }

    for(int i = 0; i < m2; i++) {
        int u, v; cin >> u >> v;
        edg2[i] = {u, v};
    }

    DSU dsu1(n+1), dsu2(n+1);

    for(int i = 0; i < m2; i++) {
        dsu2.join(edg2[i].first, edg2[i].second);
    }

    int ans = 0;

    for(int i = 0; i < m1; i++) {
        if(dsu2.find(edg1[i].first) == dsu2.find(edg1[i].second)) dsu1.join(edg1[i].first, edg1[i].second);
        else ans++;
    }

    vector<vector<int>> a(n+1);
    for(int i = 1; i <= n; i++) a[dsu2.find(i)].push_back(i);

    for(int i = 1; i <= n; i++) {
        if(a[i].empty()) continue;
        int u = a[i][0];
        for(int j = 1; j < a[i].size(); j++) {
            if(dsu1.find(u) != dsu1.find(a[i][j])) ans++;
            dsu1.join(u, a[i][j]);
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