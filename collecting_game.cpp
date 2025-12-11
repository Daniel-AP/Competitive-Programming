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

    vector<int> a(n), b(n), ind(n), ans(n), c;
    for(int i = 0; i < n; i++) cin >> a[i];

    iota(ind.begin(), ind.end(), 0);
    sort(ind.begin(), ind.end(), [&](int x, int y) { return a[x] < a[y]; });

    b[0] = a[ind[0]];

    for(int i = 1; i < n; i++) {
        b[i] = b[i-1]+a[ind[i]];
    }

    ans[ind.back()] = n-1;

    for(int i = n-2; i >= 0; i--) {
        if(b[i] >= a[ind[i+1]]) {
            ans[ind[i]] = ans[ind[i+1]];
        } else {
            ans[ind[i]] = i;
        }
    }

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