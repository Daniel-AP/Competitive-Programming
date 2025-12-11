#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n, k; cin >> n >> k;

        if(k == 0) {
            cout << 0 << endl;
            continue;
        }

        int ans = 1;
        int q = n, m = n;

        while(k > q) {
            if(ans%2 == 0) m--;
            q += m;
            ans++;
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