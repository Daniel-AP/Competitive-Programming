#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int q; cin >> q;

    multiset<int> msl, msr;

    while(q--) {

        char op; cin >> op;
        int l, r; cin >> l >> r;

        if(op == '+') {
        
            msl.insert(l);
            msr.insert(r);

        } else {

            msl.erase(msl.find(l));
            msr.erase(msr.find(r));

        }

        if(msl.empty()) {
            cout << "NO" << '\n';
            continue;
        }

        int minr = *msr.begin();
        int maxl = *msl.rbegin();

        if(minr < maxl) cout << "YES" << '\n';
        else cout << "NO" << '\n';

    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}