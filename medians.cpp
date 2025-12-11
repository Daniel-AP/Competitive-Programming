#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n, k; cin >> n >> k;

        if((n+1)/2 == k) {
            cout << 1 << endl;
            cout << 1 << endl;
        } else if(k == n || k == 1) {
            cout << -1 << endl;
        } else if(k%2 == 0) {
            cout << 3 << endl;
            cout << 1 << " " << k << " " << k+1 << endl;
        } else {
            cout << 3 << endl;
            cout << 1 << " " << k-1 << " " << k+2 << endl;
        }

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}