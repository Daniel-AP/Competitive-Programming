#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n, x, y; cin >> n >> x >> y;

        for(int i = 0; i < n; i++) {
            if(i >= x && i%2 == x%2) cout << -1 << " ";
            else if(i <= y-2 && i%2 == (y-2)%2) cout << -1 << " ";
            else cout << 1 << " ";
        }

        cout << endl;
        
    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}