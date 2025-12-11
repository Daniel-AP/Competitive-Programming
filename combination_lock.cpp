#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int n; cin >> n;

    if(n%2 == 0) {
        cout << -1 << endl;
    } else {
        for(int i = n; i >= 1; i--) cout << i << " ";
        cout << endl;
    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}