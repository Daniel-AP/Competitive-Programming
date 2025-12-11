#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int a, b, c, d; cin >> a >> b >> c >> d;
    c -= a, d -= b;

    int mn = min(a, b), mx = max(a, b);

    if((mx+mn)/(mn+1) >= 3) return void(cout << "NO" << '\n');

    mn = min(c, d), mx = max(c, d);

    if((mx+mn)/(mn+1) >= 3) return void(cout << "NO" << '\n');

    cout << "YES" << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}