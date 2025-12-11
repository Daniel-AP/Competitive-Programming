#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, x; cin >> n >> x;
    int cur = 0;

    vector<int> a(n), b(n), c(n);
    
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) cin >> c[i];
    
    for(int i = 0; i < n; i++) {
        if((x|a[i]) != x) break;
        cur |= a[i];
    }
    for(int i = 0; i < n; i++) {
        if((x|b[i]) != x) break;
        cur |= b[i];
    }
    for(int i = 0; i < n; i++) {
        if((x|c[i]) != x) break;
        cur |= c[i];
    }

    cout << (cur == x ? "YES" : "NO") << '\n';

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}