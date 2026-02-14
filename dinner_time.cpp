#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, m, p, q; cin >> n >> m >> p >> q;
    int g = gcd(n/p, n-n/p), diff = abs(m-n/p*q);

    if(n == n/p) return void(cout << (q*n == m ? "YES" : "NO") << '\n');
    
    if(diff%g == 0) cout << "YES" << '\n';
    else cout << "NO" << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}