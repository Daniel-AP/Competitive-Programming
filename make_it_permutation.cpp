#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

void solve() {

    int n; cin >> n;

    cout << 2*n-1 << "\n";
    cout << 1 << " " << 1 << " " << n << "\n";

    for(int i = 2; i <= n; i++) {
        cout << i << " " << 1 << " " << i-1 << "\n";
        cout << i << " " << i << " " << n << "\n";
    }

    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}