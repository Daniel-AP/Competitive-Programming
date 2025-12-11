#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n, m, q; cin >> n >> m >> q;

        vector<int> b(m), a(q);
        for(int i = 0; i < m; i++) cin >> b[i];
        for(int i = 0; i < q; i++) cin >> a[i];

        sort(b.begin(), b.end());

        for(int i = 0; i < q; i++) {

            int j = lower_bound(b.begin(), b.end(), a[i])-b.begin();

            if(j == 0) cout << b[0]-1 << endl;
            else if(j == m) cout << n-b[m-1] << endl;
            else {
                int l = b[j-1]; int r = b[j];
                cout << (r-l)/2 << endl;
            }

        }

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}