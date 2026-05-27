#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

struct Mono {
    int invs;
    array<int, 40> cnt;
    Mono(int invs, const array<int, 40>& cnt) : invs(invs), cnt(cnt) {}
    static Mono zero() { return {0LL, array<int, 40>{}}; }
};

Mono operator+(const Mono& a, const Mono& b) {
    
    int invs = a.invs+b.invs;
    array<int, 40> cnt{};

    for(int i = 0; i < 40; i++) cnt[i] += a.cnt[i]+b.cnt[i];
    
    array<int, 40> sx{};
    sx[40-1] = a.cnt[40-1];
    for(int i = 40-2; i >= 0; i--) sx[i] = sx[i+1]+a.cnt[i];

    for(int i = 0; i < 40-1; i++) {
        invs += b.cnt[i]*sx[i+1];
    }

    return {invs, cnt};

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
        array<int, 40> cnt{};
        cnt[x] = 1;
        seg.update(i, { 0LL, cnt });
    }

    while(q--) {
        int op; cin >> op;
        if(op == 1) {
            int l, r; cin >> l >> r;
            l--;
            cout << seg.query(l, r).invs << '\n';
        } else {
            int i, x; cin >> i >> x;
            i--; x--;
            array<int, 40> cnt{};
            cnt[x] = 1;
            seg.update(i, { 0LL, cnt });
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