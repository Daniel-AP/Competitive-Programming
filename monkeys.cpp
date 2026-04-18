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

    int n, m; cin >> n >> m;

    vector<pair<int, int>> hands(n+1);

    for(int i = 1; i <= n; i++) {
        int l, r; cin >> l >> r;
        hands[i] = {l, r};
    }

    vector<pair<int, int>> rel(m);
    set<pair<int, int>> has;

    for(int i = 0; i < m; i++) {
        int p, h; cin >> p >> h;
        rel[i] = {p, h};
        has.insert({ p, h });
    }

    DSU dsu(n+1);

    for(int i = 1; i <= n; i++) {
        if(has.find({ i, 1 }) == has.end() && hands[i].first != -1) dsu.join(i, hands[i].first);
        if(has.find({ i, 2 }) == has.end() && hands[i].second != -1) dsu.join(i, hands[i].second);
    }

    vector<int> ans(n+1, INF);

    for(int i = m-1; i >= 0; i--) {
        
    }


    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}