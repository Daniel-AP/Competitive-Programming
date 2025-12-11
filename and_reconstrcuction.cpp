#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    int n; cin >> n;

    vector<int> b(n-1), c(n);
    for(int i = 0; i < n-1; i++) cin >> b[i];

    c[0] = b[0];
    c[n-1] = b[n-2];

    for(int i = 1; i < n-1; i++) {
        c[i] |= b[i]|b[i-1];
    }

    for(int i = 0; i < n-1; i++) {
        if((c[i]&c[i+1]) != b[i]) return void(cout << -1 << '\n');
    }

    for(int x: c) cout << x << ' ';
    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}