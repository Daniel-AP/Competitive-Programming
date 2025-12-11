#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n; cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        int mn = 1e9;

        for(int i = 0; i < n-1; i++) {
            int k = max(a[i], a[i+1]);
            mn = min(mn, k);
        }

        cout << mn-1 << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}