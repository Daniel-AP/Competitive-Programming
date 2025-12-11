#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int a, b; cin >> a >> b;

    if(bit_width(b) > bit_width(a)) return void(cout << -1 << '\n');

    int cnt = 0;
    vector<int> ops;

    for(int i = 0; i < 64; i++) {
        if(((a&(1LL<<i)) != 0) != ((b&(1LL<<i)) != 0)) {
            cnt++;
            ops.push_back((1LL<<i));
        }
    }

    cout << cnt << '\n';
    for(int x: ops) cout << x << ' ';
    if(cnt) cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}