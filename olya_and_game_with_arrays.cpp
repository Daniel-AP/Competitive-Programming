#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    int n; cin >> n;

    vector<vector<int>> a(n, vector<int>());

    for(int i = 0; i < n; i++) {

        int m; cin >> m;

        for(int j = 0; j < m; j++) {
            int x; cin >> x;
            a[i].push_back(x);
        }

    }

    int ans = 0, mn = INF;

    for(int i = 0; i < n; i++) {
        sort(a[i].begin(), a[i].end());
        ans += a[i][0]; ans += a[i][1]-a[i][0];
    }

    sort(a.begin(), a.end());

    mn = min(mn, a[0][1]-a[0][0]);

    for(int i = 1; i < n; i++) {
        mn = min(mn, (a[i][1]-a[i][0])+(a[i][0]-a[0][0]));
    }

    cout << ans-mn << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}