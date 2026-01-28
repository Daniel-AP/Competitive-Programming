#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> p(n), ind(n);
    for(int i = 0; i < n; i++) cin >> p[i];

    iota(ind.begin(), ind.end(), 0);
    sort(ind.begin(), ind.end(), [&](int x, int y) { return p[x] > p[y]; });

    int mn = INF, mx = 0;

    for(int i = 0; i < n; i++) {
        mn = min(ind[i], mn);
        mx = max(ind[i], mx);
        if(mx-mn != i) return void(cout << "NO" << '\n');
    }

    cout << "YES" << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}