#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int k, q; cin >> k >> q;

        vector<int> a(k);
        for(int i = 0; i < k; i++) cin >> a[i];

        vector<int> b(q);
        for(int i = 0; i < q; i++) cin >> b[i];

        int mn = *min_element(a.begin(), a.end());

        for(int i = 0; i < q; i++) {
            cout << min(b[i], mn-1) << " ";
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