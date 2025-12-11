#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n, k1, k2; cin >> n >> k1 >> k2;
        int w, b; cin >> w >> b;

        int white = k1+k2;
        int black = 2*n-white;

        if(w <= white/2 && b <= black/2) cout << "YES" << endl;
        else cout << "NO" << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}