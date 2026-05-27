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
    static Mono zero() { return 0LL; }
};

Mono operator+(Mono a, Mono b) {
    return a.v+b.v;
}

struct SegTree {

    int n;
    vector<Mono> s;

    SegTree(int n) : n(n), s(2*n, Mono::zero()) {}

    void update(int pos, Mono val) {
        for(s[pos += n] = val; pos >>= 1; ) s[pos] = s[pos<<1]+s[pos<<1|1];
    }

    Mono query(int l, int r) {
        Mono lv = Mono::zero(), rv = Mono::zero();
        for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if(l&1) lv = lv+s[l++];
            if(r&1) rv = s[--r]+rv;
        }
        return lv+rv;
    }

};

void solve() {

    int n; cin >> n;

    SegTree seg(n);

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        if(i%2) seg.update(i, -x);
        else seg.update(i, x);
    }

    int m; cin >> m;

    while(m--) {
        int op; cin >> op;
        if(op == 0) {
            int i, j; cin >> i >> j;
            i--;
            if(i%2) seg.update(i, -j);
            else seg.update(i, j);
        } else {
            int l, r; cin >> l >> r;
            l--;
            if(l%2) cout << -seg.query(l, r).v << '\n';
            else cout << seg.query(l, r).v << '\n';
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