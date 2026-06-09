#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

struct Mono {
    int v, tm;
    Mono(int v, int tm) : v(v), tm(tm) {}
    static Mono zero() { return {0LL, INF}; }
};

Mono operator+(Mono a, Mono b) {
    if(a.tm < b.tm) return a;
    else return b;
};

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
            int l, r, v; cin >> l >> r >> v;
            seg.update(l, r, Mono{v, m});
        } else {
            int pos; cin >> pos;
            cout << seg.query(pos).v << '\n';
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