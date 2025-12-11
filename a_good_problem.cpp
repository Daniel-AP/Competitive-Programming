#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

void solve() {

    int n, l, r, k; cin >> n >> l >> r >> k;

    if(n%2 == 1) cout << l << '\n';
    else {
        if(n == 2) {
            cout << -1 << '\n';
            return;
        }
        int q = -1;
        for(int i = 0; i < 63; i++) {
            int o = (1LL<<i);
            if(o >= l && o <= r && (o&l) == 0) {
                q = o;
                break;
            }
        }
        if(q == -1) {
            cout << q << '\n';
        } else {
            if(k == n-1 || k == n) {
                cout << q << '\n';
            } else cout << l << '\n';
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