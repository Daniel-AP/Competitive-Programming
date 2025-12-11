#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;
    
    while(t--) {
        
        int n; cin >> n;
        int x, y; cin >> x >> y;
        
        cout << (n+min(x, y)-1)/min(x, y) << endl;
        
    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}