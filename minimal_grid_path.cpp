#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "\nTime elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<string> g(n);
    for(int i = 0; i < n; i++) cin >> g[i];

    vector<vector<array<int, 2>>> d(2*n-1, vector<array<int, 2>>());

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            d[i+j].push_back({ i, j });
        }
    }

    string ans; ans += g[0][0];
    
    vector<vector<bool>> can(n, vector<bool>(n));
    can[0][0] = 1;

    for(int i = 1; i < 2*n-1; i++) {
        char mn = 'Z';
        for(auto [ii, jj]: d[i]) {
            if(!(ii-1 >= 0 && can[ii-1][jj] || jj-1 >= 0 && can[ii][jj-1])) continue;
            mn = min(mn, g[ii][jj]);
        }
        for(auto [ii, jj]: d[i]) {
            if(!(ii-1 >= 0 && can[ii-1][jj] || jj-1 >= 0 && can[ii][jj-1])) continue;
            if(g[ii][jj] == mn) can[ii][jj] = 1;
        }
        ans += mn;
    }
    
    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // START_TIMER;

    int t = 1;

    while(t--) solve();

    // END_TIMER;

    return 0;

}