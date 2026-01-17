#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

int m;

struct Mono {
    int v;
    Mono(int v) : v(v%m) {}
	static Mono zero() { return Mono(1); }
};

Mono operator+(Mono a, Mono b) {
    return Mono((a.v*b.v)%m);
}

struct Tree {
	vector<Mono> s;
	int n;

	Tree(int n) : n(n), s(2*n, Mono::zero()) {}

	void update(int pos, Mono val) {
		for (s[pos += n] = val; pos >>= 1;) s[pos] = s[pos<<1] + s[pos<<1|1];
	}

	// [l, r)
	Mono query(int l, int r) {
		Mono lv = Mono::zero(), rv = Mono::zero();
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (l&1) lv = lv + s[l++];
			if (r&1) rv = s[--r] + rv;
		}
		return lv + rv;
	}
};

void solve() {

    int n; cin >> n >> m;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    string com; cin >> com;

    Tree st(n);
    for(int i = 0; i < n; i++) st.update(i, Mono(a[i]));

    int l = 0, r = n;

    for(int i = 0; i < n; i++) {
        cout << st.query(l, r).v << ' ';
        if(com[i] == 'L') {
            st.update(l, Mono(1));
            l++;
        } else {
            st.update(r-1, Mono(1));
            r--;
        }
    }

    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}