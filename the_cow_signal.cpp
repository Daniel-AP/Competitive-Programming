#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

void solve() {

    int m, n, k; cin >> m >> n >> k;

    vector<string> s(m);
    for(int i = 0; i < m; i++) cin >> s[i];

    for(int i = 0; i < m; i++) {
        for(int t = 0; t < k; t++) {
            for(int j = 0; j < n; j++) {
                string o(k, s[i][j]);
                cout << o;
            }
            cout << '\n';
        }
    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);

    int t; t = 1;

    while(t--) solve();

    return 0;

}