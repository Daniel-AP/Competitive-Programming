#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int n, b, c; cin >> n >> b >> c;

    if(b == 0 && c == 0 && n > 2) {
        cout << -1 << endl;
        return;
    }
    
    if(b == 0) {
        if(c == n-1 || c == n-2) cout << n-1 << endl;
        else if(c >= n) cout << n << endl;
        else cout << -1 << endl;
    } else {
        cout << n-max((n-1-c+b)/b, 0LL) << endl;
    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}