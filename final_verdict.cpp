#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n; cin >> n;
        int x; cin >> x;
        double s = 0;

        for(int i = 0; i < n; i++) {
            double k; cin >> k;
            s += k;
        }

        cout << (s/n == x ? "YES" : "NO") << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}