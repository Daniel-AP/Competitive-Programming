#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

#define MOD 1000000007

struct ST {

    int n;
    vector<vector<int>> st;

    ST(int n, vector<int>& arr): n(n) {

        int k = bit_width((unsigned)n);

        st.assign(n, vector<int>(k, INF));

        for(int i = 0; i < n; i++) st[i][0] = arr[i];
        for(int i = 1; i < k; i++) {
            for(int j = 0; j+(1LL<<(i-1)) < n; j++) {
                st[j][i] = min(st[j][i-1], st[j+(1LL<<(i-1))][i-1]);
            }
        }

    }

    int query(int l, int r) {

        int k = bit_width((unsigned)(r-l+1))-1;

        return min(st[l][k], st[r+1-(1LL<<k)][k]);

    }

};

void solve() {

    int n, q; cin >> n >> q;
    
    vector<int> x(n);
    for(int i = 0; i < n; i++) cin >> x[i];

    ST st(n, x);

    while(q--) {

        int a, b; cin >> a >> b;
        a--, b--;

        cout << st.query(a, b) << '\n';

    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; t = 1;

    while(t--) solve();

    return 0;

}