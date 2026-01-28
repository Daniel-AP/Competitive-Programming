#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

void solve() {

    int k, n; cin >> k >> n;

    vector<vector<int>> f(k, vector<int>(n));

    for(int i = 0; i < k; i++) {
        for(int j = 0; j < n; j++) {
            int x; cin >> x;
            f[i][x-1] = j;
        }
    }

    int ans = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            bool good = true;
            for(int o = 0; o < k; o++) {
                if(f[o][i] > f[o][j]) good = false;
            }
            if(good) ans++;
        }
    }

    cout << ans;
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);

    int t; t = 1;

    while(t--) solve();

    return 0;

}