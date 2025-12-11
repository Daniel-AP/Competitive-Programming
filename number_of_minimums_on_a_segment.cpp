#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

pair<int, int> op(pair<int, int>& p1, pair<int, int>& p2) {

    if(p1.first == p2.first) {
        return { p1.first, p1.second+p2.second };
    } else if(p1.first < p2.first) {
        return p1;
    } else {
        return p2;
    }

}

struct Seg {

	int n;
	vector<pair<int, int>> s;

	Seg(int n, vector<int> &a) : n(n), s(2*n, { INF, 0 }) {

        for(int i = 0; i < n; i++) {
            s[i+n] = { a[i], 1 };
        }
		
		for(int i = n-1; i >= 0; i--) {
            s[i] = op(s[2*i], s[2*i+1]);
		}

	}

	void update(int i, int v) {

		i += n;
		s[i].first = v;

		while(i > 1) { 
			i /= 2;
			s[i] = op(s[2*i], s[2*i+1]);
		}

	}

	pair<int, int> get(int l, int r) {

        pair<int, int> la = { INF, 0 }, ra = { INF, 0 };

        l += n;
        r += n;

        while(l < r) {

            if(l%2 == 1) {
                la = op(la, s[l]);
                l++;
            }

            if(r%2 == 1) {
                r--;
                ra = op(s[r], ra);
            }

            l /= 2;
            r /= 2;

        }

        return op(la, ra);

    }

};

void solve() {

    int n, m; cin >> n >> m;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    Seg seg(n, a);

    while(m--) {
        int o; cin >> o;
        if(o == 1) {
            int i, v; cin >> i >> v;
            seg.update(i, v);
        } else {
            int l, r; cin >> l >> r;
            pair<int, int> res = seg.get(l, r);
            cout << res.first << " " << res.second << "\n";
        }
    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; t = 1;

    while(t--) solve();

    return 0;

}