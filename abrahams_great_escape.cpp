#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k; cin >> n >> k;

    if(k == n*n-1) return void(cout << "NO" << '\n');

    vector<string> ans(n);

    for(int i = 0; i < n-1; i++) {
        ans[i] = string(n, 'D');
    }

    ans[n-1] = string(n-1, 'R')+"L";

    for(int i = 0; i < n; i++) {
        bool br = false;
        for(int j = 0; j < n; j++) {
            if(k == 0) {
                br = true;
                break;
            }
            ans[i][j] = 'U';
            k--;
        }
        if(br) break;
    }

    cout << "YES" << '\n';
    for(int i = 0; i < n; i++) cout << ans[i] << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}