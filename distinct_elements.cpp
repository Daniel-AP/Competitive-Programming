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

    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> b[i];

    a[0] = 1;

    int un = 2;

    for(int i = 1; i < n; i++) {
        if(b[i]-b[i-1] == i+1) {
            a[i] = un++;
        } else {
            int diff = i+1-(b[i]-b[i-1]);
            a[i] = a[diff-1];
        }
    }

    for(int x: a) cout << x << ' ';
    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}