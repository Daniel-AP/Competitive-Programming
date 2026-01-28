#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

void solve() {

    int n; cin >> n;

    vector<int> b(n);
    for(int i = 0; i < n; i++) cin >> b[i];

    set<int> m;
    for(int i = 0; i < n-1; i++) {
        if(b[i+1]%b[i] != 0) {
            m.insert(lcm(b[i+1], b[i])/b[i+1]);
        }
    }
    
    int ans = 1;
    for(int x: m) ans = lcm(ans, x);

    cout << ans << '\n';

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}