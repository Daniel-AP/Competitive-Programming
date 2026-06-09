#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

struct Mono {
    int v, cfi;
    Mono(int v, int cfi) : v(v), cfi(cfi) {}
    static Mono zero() { return {0, 0}; }
};

Mono operator+(Mono a, Mono b) {
    return {a.v+b.v, a.cfi+b.cfi};
}

struct SegTree {

    int n;
    vector<Mono> s;

    SegTree(int n) : n(n), s(2*n, Mono::zero()) {}

    void update(int l, int r, Mono val) {
        for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if(l&1) s[l] = s[l]+val, l++;
            if(r&1) r--, s[r] = s[r]+val;
        }
    }

    Mono query(int pos) {
        Mono res = Mono::zero();
        for(pos += n; pos > 0; pos >>= 1) res = res+s[pos];
        return res;
    }

};

void solve() {

    int n, m; cin >> n >> m;

    SegTree seg(n);

    while(m--) {
        int op; cin >> op;
        if(op == 1) {
            int l, r, a, d; cin >> l >> r >> a >> d;
            l--;
            seg.update(l, r, {a-d*(l+1), d});
        } else {
            int pos; cin >> pos;
            pos--;
            auto [v, cfi] = seg.query(pos);
            cout << v+cfi*(pos+1) << '\n';
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