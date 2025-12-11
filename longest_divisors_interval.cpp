#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n; cin >> n;
        int ans = 1;
        
        for(int i = 1; i < n; i++) {
            if(n%i == 0) ans++;
            else break;
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