#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int k, x; cin >> k >> x;

    int t1 = x, t2 = (1LL<<(k+1))-x;

    vector<int> ops;

    while(t1 != (1LL<<k) || t2 != (1LL<<k)) {
        if(t1 < t2) {
            ops.push_back(1);
            t2 -= t1;
            t1 *= 2;
        } else {
            ops.push_back(2);
            t1 -= t2;
            t2 *= 2;
        }
    }

    reverse(ops.begin(), ops.end());

    cout << ops.size() << '\n';

    for(int o: ops) cout << o << ' ';
    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}