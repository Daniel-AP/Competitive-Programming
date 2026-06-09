#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

struct DSU {
    vector<int> p, sz;
    vector<vector<int>> mks;
    int n;

    DSU(int n) : n(n), p(n), sz(n, 1), mks(n) {
        iota(all(p), 0);
        for(int i = 0; i < n; i++) mks[i].push_back(i);
    }

    int find(int a) {
        return p[a] == a ? a : (p[a] = find(p[a]));
    }

    bool join(int a, int b) {
        a = find(a), b = find(b);
        if(a == b) return 0;
        if(sz[a] < sz[b]) swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
        for(int mk: mks[b]) mks[a].push_back(mk);
        mks[b].clear();
        return 1;
    }
};

void solve() {

    int n, m; cin >> n >> m;

    vector<array<int, 2>> hm(n);

    for(int i = 0; i < n; i++) {
        cin >> hm[i][0] >> hm[i][1];
    }

    for(int i = 0; i < n; i++) {
        if(hm[i][0] != -1) hm[i][0]--;
        if(hm[i][1] != -1) hm[i][1]--;
    }

    vector<array<int, 3>> hr(m);

    for(int i = 0; i < m; i++) {
        cin >> hr[i][0] >> hr[i][1];
        hr[i][0]--;
    }

    for(int i = 0; i < m; i++) {
        hr[i][2] = hm[hr[i][0]][hr[i][1]-1];
        hm[hr[i][0]][hr[i][1]-1] = -1;
    }

    vector<int> ans(n, -1);
    DSU dsu(n);

    for(int i = 0; i < n; i++) {
        if(hm[i][0] != -1) dsu.join(i, hm[i][0]);
        if(hm[i][1] != -1) dsu.join(i, hm[i][1]);
    }

    for(int i = m-1; i >= 0; i--) {

        int rhr1 = dsu.find(hr[i][0]);
        int rhr2 = dsu.find(hr[i][2]);
        
        bool conn1 = (rhr1==dsu.find(0));
        bool conn2 = (rhr2==dsu.find(0));
        
        if(!(conn1^conn2)) {
            dsu.join(hr[i][0], hr[i][2]);
            continue;
        }

        if(!conn1) {
            for(int mk: dsu.mks[rhr1]) {
                ans[mk] = i;
            }
        }

        if(!conn2) {
            for(int mk: dsu.mks[rhr2]) {
                ans[mk] = i;
            }
        }

        dsu.join(hr[i][0], hr[i][2]);

    }

    for(int x: ans) cout << x << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}