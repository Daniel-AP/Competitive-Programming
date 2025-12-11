#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n, k; cin >> n >> k;

        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        string ans = "NO";
        int l;

        for(int i = 0; i < n; i++) {
            bool can = true;
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                if(abs(a[i]-a[j])%k == 0) can = false;
            }
            if(can) {
                ans = "YES";
                l = i+1;
            }
        }

        cout << ans << endl;
        if(ans == "YES") cout << l << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}