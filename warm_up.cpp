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

    vector<int> a(n), b(n), ind(n), has(n+1, -1);
    vector<pair<int, int>> ans;

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    iota(ind.begin(), ind.end(), 0);
    sort(ind.begin(), ind.end(), [&](int i, int j){ return a[i] > a[j]; });

    for(int i: ind) {

        if(a[i] == b[i]) { has[a[i]] = i; continue; }
        if(a[i] > b[i]) return void(cout << -1 << '\n');
        if(has[b[i]] == -1) return void(cout << -1 << '\n');

        ans.push_back({ i+1, has[b[i]]+1 });
        has[a[i]] = i;

    }

    reverse(ans.begin(), ans.end());

    cout << ans.size() << '\n';

    for(auto [i1, i2]: ans) cout << i1 << ' ' << i2 << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1, tt = 1; cin >> t;

    while(tt <= t) {
        cout << "Case #" << tt++ << ": ";
        solve();
    }

    return 0;

}