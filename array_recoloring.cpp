#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

void solve() {

    int n, k; cin >> n >> k;
    int ans = 0;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    if(k == 1) {
        int ans1 = *max_element(a.begin()+1, a.end());
        int ans2 = *max_element(a.begin(), a.end()-1);
        cout << max(a[0]+ans1, a[n-1]+ans2) << '\n';
        return;
    }

    sort(a.rbegin(), a.rend());

    for(int i = 0; i <= k; i++) ans += a[i];

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}