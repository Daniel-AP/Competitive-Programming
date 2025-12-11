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

    int i = 1, cnt = 0, prev = a[0];

    while(i+1 < n) {
        if(min(prev, a[i+1]) <= a[i] && a[i] <= max(prev, a[i+1])) {
            cnt++;
        } else {
            prev = a[i];
        }
        i++;
    }

    if(prev == a[i]) cnt++;

    cout << n-cnt << "\n";
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}