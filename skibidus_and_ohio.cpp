#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        string s; cin >> s;
        int ans = s.length();

        for(int i = 0; i < s.length()-1; i++) {
            if(s[i] == s[i+1]) ans = 1;
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