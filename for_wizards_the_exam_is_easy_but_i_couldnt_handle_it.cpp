#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<vector<int>> cnt_min(n, vector<int>(n+1));
    vector<vector<int>> cnt_max(n, vector<int>(n+1));

    for(int i = 0; i < n; i++) {
        for(int j = 1; i+j < n; j++) {
            cnt_min[i][j] = cnt_min[i][j-1]+(a[i+j]<a[i]);
            cnt_max[i][j] = cnt_max[i][j-1]+(a[i+j]>a[i]);
        }
    }

    int l = 1, r = 1, ans = 0;

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            int d = cnt_min[i][j-i]-cnt_max[i][j-i];
            if(d > ans) {
                l = i+1, r = j+1;
                ans = d;
            }
        }
    }

    cout << l << ' ' << r << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}