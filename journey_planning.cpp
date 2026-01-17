#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> b(n+1);
    for(int i = 1; i <= n; i++) cin >> b[i];

    map<int, int> cnt;

    for(int i = 1; i <= n; i++) cnt[i-b[i]] += b[i];

    int ans = 0;
    for(auto [k, v]: cnt) ans = max(ans, v);

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}