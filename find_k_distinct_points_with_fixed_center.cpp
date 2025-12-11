#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int xc, yc, k; cin >> xc >> yc >> k;

    if(yc == 0) {
        if(k%2 == 1) {
            cout << xc << " " << 0 << endl;
        }
        for(int i = 1; i <= k/2; i++) {
            cout << xc << " " << i << endl;
            cout << xc << " " << -i << endl;
        }
        return;
    }

    for(int i = 0; i < k-1 ; i++) {
        if(i%2 == k%2) {
            cout << xc << " " << -yc*(2*i+1) << endl;
        } else {
            cout << xc << " " << yc*(2*i+1) << endl;
        }
    }

    if(k == 1) {
        cout << xc << " " << yc << endl;
    } else {
        cout << xc << " " << yc*(2*(k-1)+1) << endl;
    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}