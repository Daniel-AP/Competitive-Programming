#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

void solve() {

    int n, k; cin >> n >> k;
    k--;

    vector<int> h(n);
    for(int i = 0; i < n; i++) cin >> h[i];

    int p = h[k];

    h.erase(h.begin()+k);
    n--;

    sort(h.begin(), h.end());

    int i = upper_bound(h.begin(), h.end(), p)-h.begin();
    int t = 0, prev = p;

    if(i == n) {
        cout << "YES" << '\n';
        return;
    }

    for(; i < n; i++) {
        if(t+abs(prev-h[i]) > t+abs(t-prev)) {
            cout << "NO" << '\n';
            return;
        }
        t += abs(prev-h[i]);
        prev = h[i];
    }

    cout << "YES" << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}