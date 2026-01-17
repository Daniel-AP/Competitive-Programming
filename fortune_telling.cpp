#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, x, y; cin >> n >> x >> y;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    x %= 2, y %= 2;

    for(int i = 0; i < n; i++) {
        x += a[i]%2;
        x %= 2;
    }

    if(x == y) cout << "Alice" << '\n';
    else cout << "Bob" << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}