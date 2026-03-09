#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int l, r; cin >> l >> r;
    int p = bit_width(l^r);
    int px = (l>>p)*(1LL<<p);

    cout << px+(1LL<<(p-1)) << ' ' << px+(1LL<<(p-1))-1 << ' ';

    for(int i = l; i <= r; i++) {
        if(i != px+(1LL<<(p-1)) && i != px+(1LL<<(p-1))-1) return void(cout << i << '\n');
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