#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n; cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        bool can = false;

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(gcd(a[i], a[j]) <= 2) can = true;
            }
        }

        if(can) cout << "YES" << endl;
        else cout << "NO" << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}