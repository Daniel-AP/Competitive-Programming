#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k; cin >> n >> k;

    vector<int> h(n), p(n);
    multiset<int> pms;

    for(int i = 0; i < n; i++) cin >> h[i];
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        pms.insert(p[i]);
    }

    vector<int> ind(n);

    iota(ind.begin(), ind.end(), 0);
    sort(ind.begin(), ind.end(), [&](int i, int j) { return h[i] > h[j]; });

    int d = 0;
    int mx = h[ind[0]];
    
    while(true) {
        d += k;
        if(d >= mx) return void(cout << "YES" << '\n');
        while(ind.size() > 0 && d >= h[ind.back()]) {
            pms.erase(pms.find(p[ind.back()]));
            ind.pop_back();
        }
        k -= *pms.begin();
        if(k <= 0) return void(cout << "NO" << '\n');
    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}