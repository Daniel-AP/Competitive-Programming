#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

void solve() {

    int n; cin >> n;

    if(n < 15) {
        vector<int> ans = { 1, 2, 1, 2, 3, 1, 2, 3, 2, 1, 2, 2, 2, 3, 1 };
        cout << ans[n-1] << '\n';
        return;
    }
    
    vector<int> m = { 0, 1, 2, 1, 2, 1, 1, 2, 2, 2, 1, 2, 2, 2, 3 };

    cout << n/15+m[n%15] << '\n';

    cout << sizeof(long double) << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}