#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

void solve() {

    int x, y, z, k; cin >> x >> y >> z >> k;
    int ans = 0;

    for(int i = 1; i <= x; i++) {
        for(int j = 1; j <= y; j++) {
            if(k%(i*j) == 0) {
                int m = k/(i*j);
                if(m > z) continue;
                ans = max(ans, (x-i+1)*(y-j+1)*(z-m+1));
            }
        }
    }

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}