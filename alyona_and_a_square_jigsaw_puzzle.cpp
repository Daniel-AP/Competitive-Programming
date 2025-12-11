#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;
    
    while(t--) {

        int n; cin >> n;
        int ans = 0;

        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        int s = 0;

        for(int i = 0; i < n; i++) {
            s += a[i];
            int p = sqrt(s);
            if(p*p == s && p%2 == 1) ans++;
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