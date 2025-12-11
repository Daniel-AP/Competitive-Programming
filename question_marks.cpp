#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n; cin >> n;
        string s; cin >> s;
        set<char> r(s.begin(), s.begin());

        int ans = 0;

        for(char c: r) {
            if(c != '?') continue;
            int cnt = count(s.begin(), s.end(), c);
            ans += min(cnt, n);
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