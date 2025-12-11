#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

struct Seg {

	int n;
	vector<int> s;

	Seg(int n, vector<int> &a) : n(n), s(2*n, INF) {

        for(int i = 0; i < n; i++) {
            s[i+n] = a[i];
        }
		
		for(int i = n-1; i >= 0; i--) {
			s[i] = min(s[2*i], s[2*i+1]);
		}

	}

	void update(int i, int v) {

		i += n;
		s[i] = v;

		while(i > 1) { 
			i /= 2;
			s[i] = min(s[2*i], s[2*i+1]);
		}

	}

	int get(int l, int r) {

        int la = INF, ra = INF;

        l += n;
        r += n;

        while(l < r) {

            if(l%2 == 1) {
                la = min(la, s[l]);
                l++;
            }

            if(r%2 == 1) {
                r--;
                ra = min(s[r], ra);
            }

            l /= 2;
            r /= 2;

        }

        return min(la, ra);

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
            cout << seg.get(l, r) << "\n";
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