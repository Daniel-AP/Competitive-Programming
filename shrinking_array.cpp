#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n-1; i++) if(abs(a[i]-a[i+1]) <= 1) return void(cout << 0 << '\n');

    int ans = INF;

    for(int i = 2; i < n; i++) {
        int mn = min(a[i-1], a[i-2]), mx = max(a[i-1], a[i-2]);
        int cnt = 1;
        for(int j = i-3; j >= 0; j--) {
            if(a[i] >= mn-1 && a[i] <= mx+1) ans = min(ans, cnt);
            mn = min(mn, a[j]);
            mx = max(mx, a[j]);
            cnt++;
        }
        if(a[i] >= mn-1 && a[i] <= mx+1) ans = min(ans, cnt);
    }
    
    for(int i = 0; i < n-2; i++) {
        int mn = min(a[i+1], a[i+2]), mx = max(a[i+1], a[i+2]);
        int cnt = 1;
        for(int j = i+3; j < n; j++) {
            if(a[i] >= mn-1 && a[i] <= mx+1) ans = min(ans, cnt);
            mn = min(mn, a[j]);
            mx = max(mx, a[j]);
            cnt++;
        }
        if(a[i] >= mn-1 && a[i] <= mx+1) ans = min(ans, cnt);
    }

    cout << (ans == INF ? -1 : ans) << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}