#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n; cin >> n;

        vector<int> a(n);

        for(int i = 0; i < n; i++) cin >> a[i];

        int z = count(a.begin(), a.end(), 0);
        int o = count(a.begin(), a.end(), 1);

        int p = pow(2, z);

        cout << p*o << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}