#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

#define MOD 1000000007

struct Seg {

    int n;
    vector<int> s;

    Seg(int n, vector<int>& arr) : n(n), s(2*n, INF) {

        for(int i = 0; i < n; i++) s[i+n] = arr[i];
        for(int i = n-1; i > 0; i--) s[i] = min(s[2*i], s[2*i+1]);

    }

    void update(int i, int v) {

        i += n;
        s[i] = v;

        while(i > 1) {
            i /= 2;
            s[i] = min(s[2*i], s[2*i+1]);
        }

    }

    int query(int l, int r) {

        int la = INF, ra = INF;

        l += n;
        r += n;

        while(l < r) {

            if(l%2 == 1) la = min(la, s[l++]);
            if(r%2 == 1) ra = min(ra, s[--r]);

            l /= 2;
            r /= 2;

        }

        return min(la, ra);

    }

};

void solve() {

    int n, q; cin >> n >> q;

    vector<int> x(n);
    for(int i = 0; i < n; i++) cin >> x[i];

    Seg seg(n, x);

    while(q--) {

        int o, a, b; cin >> o >> a >> b;

        if(o == 1) {
            seg.update(a-1, b);
        } else {
            cout << seg.query(a-1, b) << '\n';
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