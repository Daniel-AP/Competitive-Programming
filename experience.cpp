#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

struct DSU {
    vector<int> p, r, val, delta;
    int n;

    DSU(int n) : n(n), p(n), r(n), val(n), delta(n) {
        iota(all(p), 0);
    }

    int find(int a) {
        if(a != p[a]) {
            int pa = p[a];
            p[a] = find(p[a]);
            val[a] += val[pa]-delta[a];
            delta[a] = val[p[a]];
        }
        return p[a];
    }

    void add(int a, int v) {
        val[find(a)] += v;
    }

    int get(int a) {
        find(a);
        return val[a];
    }

    bool join(int a, int b) {
        a = find(a), b = find(b);
        if(a == b) return 0;
        if(r[a] < r[b]) swap(a, b);
        delta[b] = val[a];
        p[b] = a;
        if(r[a] == r[b]) r[a]++;
        return 1;
    }
};

void solve() {

    int n, m; cin >> n >> m;

    DSU dsu(n+1);

    while(m--) {

        string op; cin >> op;

        if(op == "join") {
            int x, y; cin >> x >> y;
            dsu.join(x, y);
        } else if(op == "add") {
            int x, v; cin >> x >> v;
            dsu.add(x, v);
        } else {
            int x; cin >> x;
            cout << dsu.get(x) << '\n';
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