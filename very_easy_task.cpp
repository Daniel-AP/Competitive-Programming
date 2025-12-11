#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int n, x, y; cin >> n >> x >> y;
    int ans = min(x, y);

    n--;

    int l(0), r(1e15), mid, secs;

    while(l <= r) {

        mid = l+(r-l)/2;
        
        int copies = mid/x+mid/y;

        if(copies >= n) {
            secs = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }

    }

    cout << ans+secs << "\n";

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; t = 1;

    while(t--) solve();

    return 0;

}