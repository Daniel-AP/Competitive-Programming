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

    int n, m, k; cin >> n >> m >> k;

    while(m--) {
        int u, v; cin >> u >> v;
    }

    DSU dsu(n+1);

    vector<array<int, 3>> q;

    for(int i = 0; i < k; i++) {
        string op; cin >> op;
        int u, v; cin >> u >> v;
        if(op == "cut") q.push_back({ 0, u, v });
        else q.push_back({ 1, u, v });
    }
    
    reverse(all(q));

    vector<string> ans;

    for(int i = 0; i < k; i++) {
        auto [op, u, v] = q[i];
        if(op == 0) {
            dsu.join(u, v);
        } else {
            ans.push_back(dsu.find(u) == dsu.find(v) ? "YES" : "NO");
        }
    }

    reverse(all(ans));

    for(string x: ans) cout << x << '\n';

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}