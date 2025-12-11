#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, a, b; cin >> n >> a >> b;
    int g = gcd(a, b);

    vector<int> c(n);

    for(int i = 0; i < n; i++) cin >> c[i];
    for(int i = 0; i < n; i++) c[i] %= g;
    
    sort(c.begin(), c.end());
    int ans = c[n-1]-c[0];

    for(int i = 1; i < n; i++) ans = min(ans, c[i-1]+g-c[i]);

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