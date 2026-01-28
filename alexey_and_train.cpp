#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

void solve() {

    int n; cin >> n;

    vector<pair<int, int>> a(n+1, { 0, 0 });
    for(int i = 1; i <= n; i++) {
        int x, y; cin >> x >> y;
        a[i] = { x, y };
    }

    vector<int> tm(n+1);
    for(int i = 1; i <= n; i++) cin >> tm[i];

    int t = 0;

    for(int i = 1; i < n; i++) {
        int k = (a[i].second-a[i].first+1)/2;
        t += a[i].first-a[i-1].second+tm[i];
        t += max(a[i].second-t, k);
    }

    t += a[n].first-a[n-1].second+tm[n];

    cout << t << "\n";
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}