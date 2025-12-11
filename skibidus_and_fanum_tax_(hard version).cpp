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

        sort(b.begin(), b.end());
        int prev = LLONG_MIN+1;
        string ans = "YES";

        for (int i = 0; i < n; i++) {
            
            int candidate1 = a[i];
            int candidate2 = LLONG_MIN;

            auto it = lower_bound(b.begin(), b.end(), prev+a[i]);
            if(it != b.end()) candidate2 = *it-a[i];

            if(candidate1 >= prev && candidate2 >= prev) {
                prev = min(candidate1, candidate2);
            } else if(candidate1 >= prev) {
                prev = candidate1;
            } else if(candidate2 >= prev) {
                prev = candidate2;
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
