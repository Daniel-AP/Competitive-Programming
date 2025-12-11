#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n, m; cin >> n >> m;

        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        int mx = *max_element(a.begin(), a.end());

        while(m--) {

            char c; cin >> c;
            int l, r; cin >> l >> r;

            int inc = c == '+' ? 1 : -1;

            if(mx >= l && mx <= r) mx += inc;

            cout << mx << " ";

        }

        cout << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}