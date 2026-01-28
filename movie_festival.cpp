#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

void solve() {

    int n; cin >> n;

    vector<pair<int, int>> a(n);

    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        a[i] = { x, y };
    }

    sort(a.begin(), a.end(), [&](pair<int, int> x, pair<int, int> y) {
        if(x.second != y.second) return x.second < y.second;
        else return x.first < y.first;
    });

    int ans = 0, prev = -INF;

    for(int i = 0; i < n; i++) {
        if(a[i].first >= prev) {
            ans++;
            prev = a[i].second;
        }
    }

    cout << ans;
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; t = 1;

    while(t--) solve();

    return 0;

}