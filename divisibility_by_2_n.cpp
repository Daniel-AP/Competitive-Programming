#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> ind(n);
    iota(ind.begin(), ind.end(), 1);
    sort(ind.begin(), ind.end(), [&](int i, int j) { return countr_zero(i) > countr_zero(j); });

    int has = 0;

    for(int i = 0; i < n; i++) {
        has += countr_zero(a[i]);
    }

    int i = 0, ans = 0;

    while(has < n && i < n) {
        has += countr_zero(ind[i]);
        ans++;
        i++;
    }

    if(has >= n) cout << ans << '\n';
    else cout << -1 << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}