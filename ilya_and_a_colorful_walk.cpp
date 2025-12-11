#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

void solve() {

    int n; cin >> n;

    vector<int> c(n);
    for(int i = 0; i < n; i++) cin >> c[i];

    int l1 = 0, l2 = INF;

    for(int i = 0; i < n; i++) {
        if(c[i] != c[0]) l1 = i;
        if(c[i] != c[n-1]) l2 = min(l2, i);
    }

    cout << max(l1, n-1-l2) << "\n";
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; t = 1;

    while(t--) solve();

    return 0;

}