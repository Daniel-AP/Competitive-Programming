#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n; cin >> n;
        
        int w = 0, h = 0;

        for(int i = 0; i < n; i++) {
            int x, y; cin >> x >> y;
            w = max(x, w), h = max(y, h);
        }

        cout << 2*w+2*h << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}