#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    int n; cin >> n;
    vector<vector<int>> m(n, vector<int>(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> m[i][j];
        }
    }

    vector<int> b(n, ((1LL<<30)-1));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(j == i) continue;
            b[i] &= m[i][j];
            b[j] &= m[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(j == i) continue;
            if((b[i]|b[j]) != m[i][j]) return void(cout << "NO" << '\n');
        }
    }

    cout << "YES" << '\n';
    for(int x : b) cout << x << ' ';
    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}