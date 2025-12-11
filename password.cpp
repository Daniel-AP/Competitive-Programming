#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n; cin >> n;
        int m = 10-n;

        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        cout << (m-1)*m/2*6 << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}