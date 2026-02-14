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
        if(r[a] == r[b]) ++r[a];
        return 1;
    }
};

void solve() {

    int n, m; cin >> n >> m;

    DSU dsu(n+1);

    while(m--) {

        string op; cin >> op;
        int u, v; cin >> u >> v;

        if(op == "union") {
            dsu.join(u, v);
        } else {
            cout << (dsu.find(u) == dsu.find(v) ? "YES" : "NO") << '\n';
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