#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int h, w, q; cin >> h >> w >> q;

    while(q--) {
    
        int op; cin >> op;

        if(op == 1) {
            int r; cin >> r;
            cout << r*w << '\n';
            h -= r;
        } else {
            int c; cin >> c;
            cout << c*h << '\n';
            w -= c;
        }

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}