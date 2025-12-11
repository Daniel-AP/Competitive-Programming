#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n, m; cin >> n >> m;

        vector<int> r(n), d(m);
        for(int i = 0; i < n; i++) cin >> r[i];
        for(int i = 0; i < m; i++) cin >> d[i];

        sort(r.rbegin(), r.rend());

        vector<int> s(n);
        for(int i = 0; i < n; i++) {
            for(int j = i; j < m; j += n) {
                s[i] += d[j];
            }
        }

        sort(s.rbegin(), s.rend());

        int ans = 0;

        for(int i = 0; i < n; i++) {
            ans += r[i]*s[i];
        }

        cout << ans << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}