#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n; cin >> n;
        
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        sort(a.begin(), a.end());

        int ans = 0;
        for(int i = 1; i < n; i++) {
            ans += a[i]-a[i-1];
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