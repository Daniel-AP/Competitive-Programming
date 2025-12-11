#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int l, r, k; cin >> l >> r >> k;

        if(l == 1 && r == 1) {
            cout << "NO" << endl;
            continue;
        }
        if(l == r) {
            cout << "YES" << endl;
            continue;
        }

        if((r-l+1)-(r/2-(l-1)/2) <= k) cout << "YES" << endl;
        else cout << "NO" << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}