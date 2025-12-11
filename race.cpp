#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

void solve() {

    int a, x, y; cin >> a >> x >> y;
    int d1 = abs(a-x);
    int d2 = abs(a-y);

    for(int i = min(x, y); i <= max(x, y); i++) {
        if(abs(i-x) < d1 && abs(i-y) < d2) {
            cout << "YES" << '\n';
            return;
        }
    }

    cout << "NO" << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}