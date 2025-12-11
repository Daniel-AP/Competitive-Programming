#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n; cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        int mn = LLONG_MAX, j = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] < mn) j = i;
            mn = min(a[i], mn);
        }

        int g = 0;
        for(int i = 0; i < n; i++) {
            if(i == j) continue;
            if(a[i]%mn == 0) g = gcd(g, a[i]);
        }

        if(g == mn) cout << "YES" << endl;
        else cout << "NO" << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}