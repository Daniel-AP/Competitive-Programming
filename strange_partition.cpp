#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n, x; cin >> n >> x;

        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        int max_beuty = 0;
        int min_beuty = 0;

        for(int i = 0; i < n; i++) {
            max_beuty += (a[i]+x-1)/x;
            min_beuty += a[i];
        }

        min_beuty = (min_beuty+x-1)/x;

        cout << min_beuty << " " << max_beuty << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}