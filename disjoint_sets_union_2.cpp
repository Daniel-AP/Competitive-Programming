#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

struct DSU {
    vector<int> p, r, mn, mx, sz;
    int n;

    DSU(int n) : n(n), p(n), r(n), mn(n), mx(n), sz(n) {
        iota(all(p), 0);
        iota(all(mn), 0);
        iota(all(mx), 0);
        fill(all(sz), 1);
    }

    int find(int a) {
        return p[a] == a ? a : (p[a] = find(p[a]));
    }

    bool join(int a, int b) {
        a = find(a), b = find(b);
        if(a == b) return 0;
        if(r[a] < r[b]) swap(a, b);
        sz[a] += sz[b];
        mn[a] = min(mn[a], mn[b]);
        mx[a] = max(mx[a], mx[b]);
        p[b] = a;
        if(r[a] == r[b]) ++r[a];
        return 1;
    }
};

void solve() {

    int n, m; cin >> n >> m;

    DSU dsu(n+1);

    while(m--) {

        string op; cin >> op;

        if(op == "union") {
            int u, v; cin >> u >> v;
            dsu.join(u, v);
        } else {
            int u; cin >> u;
            u = dsu.find(u);
            cout << dsu.mn[u] << ' ' << dsu.mx[u] << ' ' << dsu.sz[u] << '\n';
        }

    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}