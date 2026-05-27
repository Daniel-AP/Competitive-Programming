#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

int r;

struct Mono {
    array<int, 4> mat;
    Mono(const array<int, 4>& m) : mat(m) {}
    static Mono zero() { return array<int, 4>{1, 0, 0, 1}; }
};

Mono operator+(const Mono& a, const Mono& b) {
    return Mono({
        (a.mat[0]*b.mat[0]+a.mat[1]*b.mat[2])%r,
        (a.mat[0]*b.mat[1]+a.mat[1]*b.mat[3])%r,
        (a.mat[2]*b.mat[0]+a.mat[3]*b.mat[2])%r,
        (a.mat[2]*b.mat[1]+a.mat[3]*b.mat[3])%r
    });
}

struct SegTree {

    int n;
    vector<Mono> s;

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

    int n, m; cin >> r >> n >> m;

    SegTree seg(n);

    for(int i = 0; i < n; i++) {
        array<int, 4> mat;
        for(int j = 0; j < 4; j++) cin >> mat[j];
        seg.update(i, mat);
    }

    while(m--) {
        int l, r; cin >> l >> r;
        l--, r--;
        array<int, 4> mat = seg.query(l, r+1).mat;
        cout << mat[0] << ' ' << mat[1] << '\n';
        cout << mat[2] << ' ' << mat[3] << '\n';
        cout << '\n';
    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}