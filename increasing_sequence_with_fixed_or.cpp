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
    int m = popcount((unsigned int)n);

    if(m == 1) return void(cout << 1 << '\n' << n << '\n');

    cout << m+1 << '\n';

    vector<int> ans = { n };

    for(int i = 0; i < 64; i++) {
        if(n&(1LL<<i)) {
            ans.push_back(n^(1LL<<i));
        }
    }

    reverse(ans.begin(), ans.end());

    for(int x: ans) cout << x << ' ';
    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}