#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n; cin >> n;
        string s; cin >> s;

        int ans = 0;

        for(int i = 0; i < n; i++) {
            string p = s;
            p[i] = (char)('0'+'1'-p[i]);
            cout << p << endl;
            
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