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

    int n; cin >> n;

    vector<array<int, 3>> a(n);
    for(int i = 0; i < n; i++) a[i] = {-1, -1, i+1};

    for(int i = 0; i < 2*n; i++) {
        int x; cin >> x;
        if(a[x-1][0] == -1) a[x-1][0] = i;
        else a[x-1][1] = i;
    }

    sort(all(a));

    SegTree seg(2*n);
    vector<int> ans(n);

    for(int i = n-1; i >= 0; i--) {
        ans[a[i][2]-1] = seg.query(0, a[i][1]).v;
        seg.update(a[i][1], 1);
    }

    for(int x: ans) cout << x << ' ';
    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}