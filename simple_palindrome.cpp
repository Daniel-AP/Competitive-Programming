#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n; cin >> n;
        string ans;

        vector<char> v = { 'a', 'e', 'i', 'o', 'u' };

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n/5+(i<n%5); j++) {
                ans += v[i];
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