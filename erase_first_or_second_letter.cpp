#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n; cin >> n;
        string s; cin >> s;
        
        unordered_set<char> letters;
        int ans = 0;

        for(int i = 0; i < n; i++) {
            letters.insert(s[i]);
            ans += letters.size();
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