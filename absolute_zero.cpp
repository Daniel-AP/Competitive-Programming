#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> ops;

    for(int i = 0; i < 40; i++) {
        int mx = *max_element(a.begin(), a.end());
        int mn = *min_element(a.begin(), a.end());
        ops.push_back((mn+mx)/2);
        for(int j = 0; j < n; j++) {
            a[j] = abs(a[j]-(mn+mx)/2);
        }
    }

    bool good = true;

    for(int i = 0; i < n; i++) {
        if(a[i] != 0) good = false;
    }

    if(!good) return void(cout << -1 << '\n');

    cout << ops.size() << '\n';
    for(int x: ops) cout << x << ' ';
    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}