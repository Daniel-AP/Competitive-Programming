#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n; cin >> n;
        int s = 0;

        for(int i = 0; i < n-2; i++) {
            int x; cin >> x;
            s -= x;
        }

        int l, k; cin >> l >> k;

        cout << k-(s+l) << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}