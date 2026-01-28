#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int c1 = 0, c2 = 0;
    
    for(int i = 0; i < n-1; i++) {

        int p1 = c1, p2 = c2;

        c1 = max({ p1+a[i], abs(p1+a[i]), p2+a[i], abs(p2+a[i]) });
        c2 = min({ p1+a[i], abs(p1+a[i]), p2+a[i], abs(p2+a[i]) });
        
    }

    cout << max({ c1+a[n-1], abs(c1+a[n-1]), c2+a[n-1], abs(c2+a[n-1]) }) << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}