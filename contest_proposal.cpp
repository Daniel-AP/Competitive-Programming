#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;
    
    while(t--) {

        int n; cin >> n;

        vector<int> a(n), b(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];

        int ans = 0;

        for(int i = 0; i < n; i++) {
            int j = lower_bound(b.begin(), b.end(), a[i])-b.begin();
            ans = max(j-i, ans);
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