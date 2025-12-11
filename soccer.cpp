#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int x1, y1; cin >> x1 >> y1;
        int x2, y2; cin >> x2 >> y2;
        
        if(x1 < y1 && x2 < y2 || y1 > x1 && y2 >> x2) cout << "YES" << endl;
        else cout << "NO" << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}