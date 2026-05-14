#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int p, q; cin >> p >> q;

    for(int d = 1; d*d <= 2*p+4*q+1; d++) {
        if((2*p+4*q+1)%d != 0) continue;
        if((d-1)%2) continue;
        int n = (d-1)/2, m = (p+2*q-n)/(2*n+1);
        if(q > n*m+min(n, m)) continue;
        return void(cout << n << ' ' << m << '\n');
    }

    cout << -1 << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}