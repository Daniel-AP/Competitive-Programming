#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n; cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        int mx1 = 0, mx2 = 0;

        for(int i = 0; i < n; i++) {
            if(i%2 == 0) {
                mx1 = max(a[i], mx1);
            } else {
                mx2 = max(a[i], mx2);
            }
        }

        cout << max(mx1+(n-n/2), mx2+n/2) << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}