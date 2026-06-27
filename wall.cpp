#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

struct Lazy {
    int l, r;
    static Lazy zero() { return {-INF, INF}; }
    bool is_zero() { return l == -INF && r == INF; }
};
struct Mono {
    int v;
    static Mono zero() { return {0}; }
    void apply_lazy(Lazy d, int l, int r) { v = clamp(v, d.l, d.r); }
};
Lazy operator+ (Lazy a, Lazy b) {
    return {
        clamp(a.l, b.l, b.r),
        clamp(a.r, b.l, b.r)
    };
}
Mono operator+ (Mono a, Mono b) { return a; }
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
        for (int i = len-1; i >= 1; --i) data[i] = data[i<<1]+data[i<<1|1];
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
    Mono point(int pos) {
        return point(1, 0, len, pos);
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
        int m = l+((r-l)>>1);
        update(i<<1, l, m, x); update(i<<1|1, m, r, x);
        data[i] = data[i<<1]+data[i<<1|1];
    }
    Mono point(int i, int l, int r, int pos) {
        push(i, l, r);
        if(i == pos+len) return data[i];
        int m = l+((r-l)>>1);
        if(pos >= m) return point(i<<1|1, m, r, pos);
        else return point(i<<1, l, m, pos);
    }
};

void solve() {

    int n, k; cin >> n >> k;

    SegTreeLazy seg(n);

    while(k--) {
        int op, l, r, h; cin >> op >> l >> r >> h;
        if(op == 1) seg.update(l, r+1, {h, INF});
        else seg.update(l, r+1, {-INF, h});
    }

    for(int i = 0; i < n; i++) cout << seg.point(i).v << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}