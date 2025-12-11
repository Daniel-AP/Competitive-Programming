#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    int n, q; cin >> n >> q;

    vector<int> c(n), a(n), prefix_c(n+1), prefix_a(n+1);

    for(int i = 0; i < n; i++) cin >> c[i];
    for(int i = 0; i < n; i++) a[i] = (c[i] == 1 ? 2 : 1);

    partial_sum(c.begin(), c.end(), prefix_c.begin()+1);
    partial_sum(a.begin(), a.end(), prefix_a.begin()+1);

    while(q--) {

        int l, r; cin >> l >> r;

        int sa = prefix_a[r]-prefix_a[l-1];
        int sc = prefix_c[r]-prefix_c[l-1];
        int s = r-l+1;

        if(sa > sc) {
            cout << "NO" << '\n';
        } else if(sa == sc) {
            cout << "YES" << '\n';
        } else {
            if(sa > s) cout << "YES" << '\n';
            else cout << (s == 1 ? "NO" : "YES") << '\n';
        }

    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}