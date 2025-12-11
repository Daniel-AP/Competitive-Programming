#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

void solve() {

    int n, m; cin >> n >> m;

    vector<string> a(n), b(n);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    int ans = 0;

    for(int i = 0; i < m; i++) {
        bool good = true;
        set<char> h;
        for(int j = 0; j < n; j++) h.insert(a[j][i]);
        for(int j = 0; j < n; j++) {
            if(h.count(b[j][i])) good = false;
        }
        if(good) ans++;
    }

    cout << ans;
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);

    int t; t = 1;

    while(t--) solve();

    return 0;

}