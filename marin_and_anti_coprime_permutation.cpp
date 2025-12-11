#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;
    int mod = 998244353;

    while(t--) {

        int n; cin >> n;
        int m = 1;

        if(n%2 == 1) {
            cout << 0 << endl;
            continue;
        }

        for(int i = 1; i <= n; i++) {

            int k = n/2-i/2;
            int l = n-i+1-k;

            if(i%2 == 1) {
                m = (m%mod*k%mod)%mod;
            } else {
                m = (m%mod*l%mod)%mod;
            }
        }

        cout << m << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}