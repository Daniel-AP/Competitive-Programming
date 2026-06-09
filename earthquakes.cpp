#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

struct Mono {
    int v;
    Mono(int v) : v(v) {}
    static Mono zero() { return INF; }
};

Mono operator+(Mono a, Mono b) {
    return min(a.v, b.v);
}

struct SegTree {

    int n;
    vector<Mono> s;

    SegTree(int sz) : n(bit_ceil((unsigned int)sz)), s(2*n, Mono::zero()) {}

    void update(int pos, Mono val) {
        for(s[pos += n] = val; pos >>= 1; ) s[pos] = s[pos<<1]+s[pos<<1|1];
    }

    int find(int l, int r, int p) {

        vector<int> lv, rv;

        for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if(l&1) lv.push_back(l++);
            if(r&1) rv.push_back(--r);
        }

        reverse(all(rv));

        for(int c: lv) {
            if(s[c].v > p) continue;
            int x = c;
            while(x < n) {
                int lc = x<<1;
                int rc = x<<1|1;
                if(s[lc].v <= p) x = lc;
                else x = rc;
            }
            return x-n;
        }

        for(int c: rv) {
            if(s[c].v > p) continue;
            int x = c;
            while(x < n) {
                int lc = x<<1;
                int rc = x<<1|1;
                if(s[lc].v <= p) x = lc;
                else x = rc;
            }
            return x-n;
        }

        return -1;

    }

};

void solve() {

    int n, m; cin >> n >> m;

    SegTree seg(n);

    while(m--) {
        int op; cin >> op;
        if(op == 1) {
            int i, h; cin >> i >> h;
            seg.update(i, h);
        } else {
            int l, r, p; cin >> l >> r >> p;
            int cnt = 0, j = -1;
            while((j = seg.find(l, r, p)) != -1) {
                seg.update(j, INF);
                cnt++;
            }
            cout << cnt << '\n';
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