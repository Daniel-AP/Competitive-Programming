#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

void solve() {

    int n, x; cin >> n >> x;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a.rbegin(), a.rend());

    int cnt = 0, curr = 0;

    for(int i = 0; i < n; i++) {
        curr++;
        if(a[i]*curr >= x) {
            cnt++;
            curr = 0;
        }
    }

    cout << cnt << "\n";
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}