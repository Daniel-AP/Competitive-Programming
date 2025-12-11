#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n; cin >> n;
        
        if(n < 4) {
            cout << n/2+1 << endl;
            continue;
        }

        int k = 4;
        int ans = 2;

        while(k < n) {
            k = (k+1)*2;
            ans++;
        }
        
    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}