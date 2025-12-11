#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n, k; cin >> n >> k;

        vector<int> l(n), r(n), m(n);
        for(int i = 0; i < n; i++) cin >> l[i];
        for(int i = 0; i < n; i++) cin >> r[i];

        int ans = 0;

        for(int i = 0; i < n; i++) {
            m[i] = min(l[i],r[i]);
        }

        sort(m.rbegin(), m.rend());

        for(int i = 0; i < n; i++) ans += max(l[i], r[i]);
        for(int i = 0; i < k-1; i++) ans += m[i];

        cout << ans+1 << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}