#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        string s; cin >> s;
        int ans = 1;
        bool leading = true;

        if(s[0] == '0') {
            cout << 0 << endl;
            continue;
        }

        for(int i = 0; i < s.length(); i++) {
            if(s[i] != '?') leading = false;
            if(s[i] == '?') {
                ans *= (10-leading);
                leading = false;
            }
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