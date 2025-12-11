#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int a, b; cin >> a >> b;
        int l = 0, r = a, mid, ans = 0;

        while(l <= r) {
            mid = l+(r-l)/2;
            if(b-2*mid <= a-mid) {
                ans = a-mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
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