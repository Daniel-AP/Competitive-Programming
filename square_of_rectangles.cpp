#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int l1, b1, l2, b2, l3, b3; cin >> b1 >> l1 >> b2 >> l2 >> b3 >> l3;

    bool ok = false;

    if(b1 == b2 && b2 == b3 && l1+l2+l3 == b1) ok = true;
    if(l2 == l3 && b1 == b2+b3 && l1+l2 == b1) ok = true;
    if(b2 == b3 && l2+l3 == l1 && b2+b1 == l1) ok = true;
    if(l1 == l2 && l2 == l3 && l1 == b1+b2+b3) ok = true;

    cout << (ok ? "YES" : "NO") << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}