#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

struct Mono {
    bitset<40> bs;
    Mono(const bitset<40>& bs) : bs(bs) {}
    static Mono zero() { return bitset<40>{}; }
};

Mono operator+(const Mono& a, const Mono& b) {
    return { a.bs|b.bs };
}

struct SegTree {

    int n;
    vector<Mono> s;

    SegTree(int n) : n(n), s(2*n, Mono::zero()) {}

    void update(int pos, const Mono& val) {
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

    int n, q; cin >> n >> q;

    SegTree seg(n);

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        x--;
        bitset<40> bs{};
        bs.set(x);
        seg.update(i, bs);
    }

    while(q--) {
        int op; cin >> op;
        if(op == 1) {
            int l, r; cin >> l >> r;
            l--;
            cout << seg.query(l, r).bs.count() << '\n';
        } else {
            int i, x; cin >> i >> x;
            i--, x--;
            bitset<40> bs{};
            bs.set(x);
            seg.update(i, bs);
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