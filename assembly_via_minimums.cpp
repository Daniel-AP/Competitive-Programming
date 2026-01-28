#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    int n; cin >> n;
    int m = n*(n-1)/2;

    vector<int> a(m), ans(n, -INF);
    for(int i = 0; i < m; i++) cin >> a[i];

    sort(a.begin(), a.end());

    int k = 0;

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            ans[i] = max(ans[i], a[k]);
            ans[j] = max(ans[j], a[k]);
            k++;
        }
    }

    for(int x: ans) cout << x << ' ';
    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}