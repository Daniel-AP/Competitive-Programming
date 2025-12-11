#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

void solve() {

    int n, x; cin >> n >> x;

    if(x == 0) {
        if(n%2 == 0) {
            cout << n << '\n';
        } else {
            if(n > 2) cout << 5+n-2 << '\n';
            else cout << -1 << '\n';
        }
        return;
    }

    if(popcount(x) <= n) {
        if(popcount(x)%2 == n%2) {
            cout << x+(n-popcount(x)) << '\n';
        } else {
            if(x == 1) {
                cout << 5+n-2 << '\n';
            } else {
                cout << x+n-popcount(x)+1 << '\n';
            }
        }
    } else {
        cout << x << '\n';
    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}