#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int n; cin >> n;

    while(n--) {

        string s; cin >> s;
        int m = s.length();
        int ans = m;

        for(int i = 1; i <= m/2; i++) {

            if(m%i != 0) continue;

            string k;

            for(int j = 0; j < m; j++) {
                k += s[j%i];
            }

            if(k == s) {
                ans = i;
                break;
            }

        }

        cout << ans << endl;

        if(n) cout << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}