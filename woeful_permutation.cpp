#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n; cin >> n;

        if(n%2 == 1) cout << 1 << " ";

        for(int i = 1+n%2; i <= n; i++) {
            if(i%2 == 0) cout << i+1 << " ";
            else cout << i-1 << " ";
        }
        
        cout << endl;
        
    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}