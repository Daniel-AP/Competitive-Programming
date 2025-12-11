#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

void solve() {

    int n, k; cin >> n >> k;

    vector<int> c(n);
    for(int i = 0; i < n; i++) cin >> c[i];

    if(c[0] == c[n-1]) {
        int cnt = count(c.begin(), c.end(), c[0]);
        if(cnt >= k) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    } else {
        int cnt = 0, start = 0;
        for(int i = 0; i < n; i++) {
            start++;
            if(c[i] == c[0]) cnt++;
            if(cnt == k) break;
        }
        cnt = 0;
        for(int i = start; i < n; i++) {
            if(c[i] == c[n-1]) cnt++;
        }
        if(cnt >= k) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}