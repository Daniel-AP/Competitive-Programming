#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n, m, l, r; cin >> n >> m >> l >> r;

        l += min(n-m, -l);

        int diff = r-l-m;

        r -= diff;

        cout << l << " " << r << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}