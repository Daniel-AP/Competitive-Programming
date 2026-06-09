#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

struct Lazy {
    int v;
    static Lazy zero() { return {0}; }
    bool is_zero() { return v == 0; }
};
struct Mono {
    int v;
    static Mono zero() { return {INF}; }
    void apply_lazy(Lazy d, int l, int r) { v += d.v; }
};
Lazy operator+ (Lazy a, Lazy b) { return {a.v+b.v}; }
Mono operator+ (Mono a, Mono b) { return {min(a.v, b.v)}; }
struct SegTreeLazy {
    int len;
    vector<Mono> data;
    vector<Lazy> lazy;
    SegTreeLazy(int n) {
        len = bit_ceil(unsigned(n));
        data.assign(2*len, Mono::zero());
        lazy.assign(2*len, Lazy::zero());
    };
    SegTreeLazy(int n, vector<Mono> &a) {
        len = bit_ceil(unsigned(n));
        data.assign(2*len, Mono::zero());
        lazy.assign(2*len, Lazy::zero());
        for (int i = 0; i < n; ++i) data[i+len] = a[i];
        for (int i = len-1; i >= 1; --i) data[i] = data[i*2]+data[i*2+1];
    }
    int ql, qr;
    void update(int l, int r, Lazy x) {
        ql = l, qr = r;
        update(1, 0, len, x);
    }
    Mono query(int l, int r) {
        ql = l, qr = r;
        return query(1, 0, len);
    }
    void push(int i, int l, int r) {
        if (lazy[i].is_zero()) return;
        if (i < len) {
            lazy[i<<1] = lazy[i<<1]+lazy[i];
            lazy[i<<1|1] = lazy[i<<1|1]+lazy[i];
        }
        data[i].apply_lazy(lazy[i], l, r);
        lazy[i] = Lazy::zero();
    }
    Mono query(int i, int l, int r) {
        if (r <= ql || qr <= l) return Mono::zero();
        push(i, l, r);
        if (ql <= l && r <= qr) return data[i];
        int m = (l+r)>>1;
        return query(i<<1, l, m)+query(i<<1|1, m, r);
    }
    void update(int i, int l, int r, Lazy x) {
        if (l == r) return;
        push(i, l, r);
        if (r <= ql || qr <= l) return;
        if (ql <= l && r <= qr) {
            lazy[i] = lazy[i]+x;
            push(i, l, r);
            return;
        }
        int m = (l+r)>>1;
        update(i<<1, l, m, x); update(i<<1|1, m, r, x);
        data[i] = data[i<<1]+data[i<<1|1];
    }
};

void solve() {

    int n, m; cin >> n >> m;

    vector<Mono> a(n, {0});
    SegTreeLazy seg(n, a);

    while(m--) {
        int op; cin >> op;
        if(op == 1) {
            int l, r, v; cin >> l >> r >> v;
            seg.update(l, r, {v});
        } else {
            int l, r; cin >> l >> r;
            cout << seg.query(l, r).v << '\n';
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