#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int y, x; cin >> y >> x;
        int spiral = max(y, x);
        int current = spiral*spiral;
        int prev = (spiral-1)*(spiral-1);

        if(spiral%2 == 0) {
            cout << current-x+1-spiral+y << endl;
        } else {
            cout << prev+x+spiral-y << endl;
        }

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}