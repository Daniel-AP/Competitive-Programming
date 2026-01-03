#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> cnt(n+1);

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        cnt[x]++;
    }

    int ans = 0;

    for(int i = 1; i <= n; i++) {
        ans += cnt[i]/2;
    }

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}