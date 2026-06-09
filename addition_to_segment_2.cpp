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

    void update(int l, int r, Mono v) {
        for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if(l&1) s[l] = s[l]+v, l++;
            if(r&1) r--, s[r] = s[r]+v;
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
            seg.update(l, r, Mono{v});
        } else {
            int i; cin >> i;
            cout << seg.query(i).v << '\n';
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