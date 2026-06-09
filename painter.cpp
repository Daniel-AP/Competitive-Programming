#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

const int N = 1000005;
const int M = 500000;

struct Lazy {
    char c;
    bool z;
    static Lazy zero() { return {'W', 1}; }
    bool is_zero() { return z; }
};
struct Mono {
    int cntB, cntSeg;
    bool startB, endB;
    static Mono zero() { return {0, 0, 0, 0}; }
    void apply_lazy(Lazy d, int l, int r) {
        if(d.z) return;
        if(d.c == 'W') cntB = 0, cntSeg = 0, startB = 0, endB = 0;
        else cntB = r-l, cntSeg = 1, startB = 1, endB = 1;
    }
};
Lazy operator+ (Lazy a, Lazy b) { return (b.z ? a : b); }
Mono operator+ (Mono a, Mono b) {
    return {a.cntB+b.cntB, a.cntSeg+b.cntSeg-(a.endB&&b.startB), a.startB, b.endB};
}
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
};

void solve() {

    int n; cin >> n;

    SegTreeLazy seg(N);

    while(n--) {
        char c;
        int x, l; cin >> c >> x >> l;
        seg.update(x+M, x+l+M, {c, 0});
        const auto& [cntB, cntSeg, startB, endB] = seg.query(0, N);
        cout << cntSeg << ' ' << cntB << '\n';
    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}