#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

void solve() {

    int n; cin >> n;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int ans = 0;

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            int k = lower_bound(a.begin()+j+1, a.end(), a[i]+a[j])-a.begin()-1;
            int q = upper_bound(a.begin()+j+1, a.end(), a[n-1]-a[i]-a[j])-a.begin();
            ans += max(k-q+1, 0LL);
        }
    }

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}