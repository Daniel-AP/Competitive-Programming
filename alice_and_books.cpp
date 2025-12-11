#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int n; cin >> n;

    int mx = 0;

    for(int i = 0; i < n-1; i++) {
        int x; cin >> x;
        mx = max(mx, x);
    }

    int x; cin >> x;

    cout << mx+x << endl;
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}