#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n; cin >> n;

        vector<int> a(n), b(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        int s = 0;
        for(int i = 0; i < n; i++) s += a[i];

        int mx = s;

        for(int i = 0; i < n; i++) {

            int l = 1;
            int o = 0;

            for(int j = 0; j < n; j++) {

                if(i == j) continue;
                
                int r = 0;
                int m = a[j];
                while(m%2 == 0) {
                    m /= 2;
                    r++;
                }

                o += m;
                l *= pow(2, r);

            }

            mx = max(o+a[i]*l, mx);

        }

        cout << mx << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}