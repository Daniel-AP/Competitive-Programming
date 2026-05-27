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
    static Mono zero() { return {-INF}; } 
};

Mono operator+(Mono a, Mono b) {
    return max(a.v, b.v);
}

struct SegTree {

    int n;
    vector<Mono> s;

    SegTree(int x) : n(bit_ceil((unsigned int)x)), s(2*n, Mono::zero()) {}

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

    int find(int k) {

        if(s[1].v < k) return -1;

        int x = 1;

        while(x < n) {
            int l = x<<1, r = x<<1|1;
            if(s[l].v >= k) {
                x = l;
            } else {
                x = r;
            }
        }

        return x-n;

    }

};

void solve() {

    int n, m; cin >> n >> m;

    SegTree seg(n);
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        seg.update(i, x);
    }

    while(m--) {
        int op; cin >> op;
        if(op == 1) {
            int i, v; cin >> i >> v;
            seg.update(i, v);
        } else {
            int x; cin >> x;
            cout << seg.find(x) << '\n';
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