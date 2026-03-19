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

    vector<pair<int, int>> wh1(m1), wh2(m2);

    for(int i = 0; i < m1; i++) {
        int u, v; cin >> u >> v;
        wh1[i] = {u, v};
    }

    for(int i = 0; i < m2; i++) {
        int u, v; cin >> u >> v;
        wh2[i] = {u, v};
    }

    DSU dsu1(n+1), dsu2(n+1);

    for(int i = 0; i < m2; i++) {
        dsu2.join(wh2[i].first, wh2[i].second);
    }

    int ans = 0;

    for(int i = 0; i < m1; i++) {
        if(dsu2.find(wh1[i].first) == dsu2.find(wh1[i].second)) dsu1.join(wh1[i].first, wh1[i].second);
        else ans++;
    }

    vector<vector<int>> cc(n+1);
    for(int i = 1; i <= n; i++) cc[dsu2.find(i)].push_back(i);

    for(int i = 1; i <= n; i++) {
        if(cc[i].empty()) continue;
        int u = cc[i][0];
        for(int j = 1; j < cc[i].size(); j++) {
            if(dsu1.find(u) != dsu1.find(cc[i][j])) ans++;
            dsu1.join(u, cc[i][j]);
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