#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

void solve() {

    int n, k, x; cin >> n >> k >> x;

    vector<int> a(n), prefix(n+1);
    for(int i = 0; i < n; i++) cin >> a[i];

    partial_sum(a.begin(), a.end(), prefix.begin()+1);

    int cnt = 0;

    for(int i = 1; i <= n; i++) {

        int rng = 0;

        if(prefix[n]-prefix[i-1] < x) {
            rng += (x+prefix[i-1]-1)/prefix[n];
        }

        if(k > rng) cnt += k-rng;

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