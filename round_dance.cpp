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

    int n; cin >> n;

    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];

    vector<set<int>> b(n+1);

    for(int i = 1; i <= n; i++) {
        b[i].insert(a[i]);
        b[a[i]].insert(i);
    }

    DSU dsu(n+1);
    for(int i = 1; i <= n; i++) dsu.join(i, a[i]);

    map<int, bool> can;
    int mn = 0, mx = 0;

    for(int i = 1; i <= n; i++) {
        int u = dsu.find(i);
        if(can.find(u) == can.end()) can[u] = 1;
        if(b[i].size() < 2) can[u] = 0;
    }

    for(auto [k, v]: can) mn += v;
    if(mn < can.size()) mn++;

    for(int i = 1; i <= n; i++) {
        if(dsu.find(i) == i) mx++;
    }

    cout << max(mn, 1LL) << ' ' << mx << '\n';

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}