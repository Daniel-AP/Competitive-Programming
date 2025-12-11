#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

void solve() {

    int n, m; cin >> n >> m;

    vector<int> t(m), ans(m, -1);
    multiset<int> h;

    for(int i = 0; i < n; i++) { int x; cin >> x; h.insert(x); }
    for(int i = 0; i < m; i++) cin >> t[i];

    for(int i = 0; i < m; i++) {
        if(h.empty()) continue;
        auto it = h.upper_bound(t[i]);
        if(it != h.begin()) {
            ans[i] = *(--it);
            h.erase(it);
        }
    }
    
    for(int x: ans) cout << x << '\n';

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; t = 1;

    while(t--) solve();

    return 0;

}