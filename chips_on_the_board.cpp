#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    int n; cin >> n;

    vector<int> a(n), b(n);
    
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    int mn1 = *min_element(a.begin(), a.end()), mn2 = *min_element(b.begin(), b.end());
    int ans1 = 0, ans2 = 0;

    for(int i = 0; i < n; i++) {
        ans1 += mn1+b[i];
    }

    for(int i = 0; i < n; i++) {
        ans2 += mn2+a[i];
    }

    cout << min(ans1, ans2) << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}