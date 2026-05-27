#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

struct Mono {
    array<array<int, 3>, 3> v;
    int s;
    Mono() : v{}, s(0) {}
    Mono(array<array<int, 3>, 3> v, int s) : v(v), s(s) {}
    static Mono zero() { return {array<array<int, 3>, 3>{{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}}, 0}; }
};

Mono operator+(Mono a, Mono b) {

    Mono res{};
    res.s = a.s+b.s;
    
    int mx1 = max({ a.v[0][2], b.v[0][2], a.v[2][2]+b.v[1][2] });

    if(a.v[0][2] == mx1) res.v[0] = a.v[0];
    else if(b.v[0][2] == mx1) res.v[0] = b.v[0];
    else res.v[0] = {a.v[2][0], b.v[1][1], a.v[2][2]+b.v[1][2]};

    int mx2 = max({ a.v[1][2], a.s+b.v[1][2] });

    if(a.v[1][2] == mx2) res.v[1] = a.v[1];
    else res.v[1] = {a.v[1][0], b.v[1][0], a.s+b.v[1][2]};

    int mx3 = max({ b.v[2][2], b.s+a.v[2][2] });

    if(b.v[2][2] == mx3) res.v[2] = b.v[2];
    else res.v[2] = {a.v[2][0], b.v[2][1], b.s+a.v[2][2]};

    return res;

}

struct SegTree {

    vector<Mono> s;
    int n;

    SegTree(int n) : n(n), s(2*n, Mono::zero()) {}

    void update(int pos, Mono val) {
        for(s[pos += n] = val; pos >>= 1;) s[pos] = s[pos<<1]+s[pos<<1|1];
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

    int n, m; cin >> n >> m;

    SegTree seg(n);
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        int y = max(x, 0LL);
        Mono m{array<array<int, 3>, 3>{{{i, i, y}, {i, i, y}, {i, i, y}}}, x};
        seg.update(i, m);
    }

    cout << seg.query(0, n).v[0][2] << '\n';

    while(m--) {
        int i, x; cin >> i >> x;
        int y = max(x, 0LL);
        Mono m{array<array<int, 3>, 3>{{{i, i, y}, {i, i, y}, {i, i, y}}}, x};
        seg.update(i, m);
        cout << seg.query(0, n).v[0][2] << '\n';
    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}