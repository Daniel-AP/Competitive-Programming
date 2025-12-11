#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n, r; cin >> n >> r;

        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        int ans = 0, total = 0;

        for(int i = 0; i < n; i++) {
            ans += a[i]/2*2;
            total += a[i]-a[i]/2*2;
            r -= a[i]/2;
        }

        if(r >= total) ans += total;
        else {
            total -= r;
            ans += r-total;
        }

        cout << ans << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}