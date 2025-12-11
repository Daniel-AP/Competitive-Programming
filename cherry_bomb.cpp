#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n, k; cin >> n >> k;
        int s = -1, ans = 0, mn = LLONG_MAX, mx = 0;
        bool can = true;

        vector<int> a(n), b(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];

        for(int i = 0; i < n; i++) {
            mn = min(mn, a[i]); mx = max(mx, a[i]);
            if(b[i] != -1 && s != -1 && a[i]+b[i] != s) can = false;
            if(s != -1 && a[i] > s) can = false;
            if(s != -1 && a[i]+k < s) can = false;
            if(b[i] != -1) s = a[i]+b[i];
        }

        if(!can) {
            cout << 0 << endl;
            continue;
        }

        if(s == -1) {
            cout << k-mx+mn+1 << endl;
            continue;
        }

        cout << 1 << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}