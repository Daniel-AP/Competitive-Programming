#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int a, b, n, m; cin >> a >> b >> n >> m;

    if(a <= b) {
        if(a < m) return void(cout << "No" << '\n');
        a -= m;
    } else {
        if(b < m) return void(cout << "No" << '\n');
        b -= m;
    }

    if(a+b >= n) cout << "Yes" << '\n';
    else cout << "No" << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}