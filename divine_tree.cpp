#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, m; cin >> n >> m;

    if(!(m >= n && m <= n*(n+1)/2)) return void(cout << -1 << '\n');

    int diff = m-n;

    vector<int> ans(n);
    set<int> has;

    for(int i = 1; i <= n; i++) has.insert(i);

    for(int i = 1; i <= n && diff > 0; i++) {
        ans[min(diff, n-i)] = i;
        diff -= min(diff, n-i);
        has.erase(i);
    }

    for(int i = 0; i < n; i++) {
        if(ans[i] != 0) continue;
        ans[i] = *has.begin();
        has.erase(has.begin());
    }

    cout << ans[0] << '\n';

    for(int i = 0; i+1 < n; i++) {
        cout << ans[i] << ' ' << ans[i+1] << '\n';
    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}