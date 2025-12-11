#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, m; cin >> n >> m;

    vector<int> cnt(m+1);
    vector<vector<int>> a(n, vector<int>());

    for(int i = 0; i < n; i++) {

        int l; cin >> l;

        a[i].resize(l);

        for(int j = 0; j < l; j++) {
            cin >> a[i][j];
            cnt[a[i][j]]++;
        }

    }

    for(int i = 1; i <= m; i++) if(cnt[i] == 0) return void(cout << "NO" << '\n');

    int ones = 0;

    for(int i = 0; i < n; i++) {
        for(int x: a[i]) {
            if(cnt[x] == 1) {
                ones++;
                break;
            }
        }
    }

    if(n-ones >= 2) cout << "YES" << '\n';
    else cout << "NO" << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}