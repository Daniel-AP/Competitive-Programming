#include <bits/stdc++.h> 
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while (t--) {

        int n, m; cin >> n >> m;

        vector<int> a(n), b(m);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];

        int prev = LLONG_MIN;
        string ans = "YES";

        for (int i = 0; i < n; i++) {
            
            if(a[i] >= prev && b[0]-a[i] >= prev) {
                prev = min(a[i], b[0]-a[i]);
            } else if(a[i] >= prev) {
                prev = a[i];
            } else if(b[0]-a[i] >= prev) {
                prev = b[0]-a[i];
            } else ans = "NO";

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
