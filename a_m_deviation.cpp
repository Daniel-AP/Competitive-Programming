#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int a1, a2, a3; cin >> a1 >> a2 >> a3;

        if(abs(a1+a3-2*a2)%3 == 0) cout << 0 << endl;
        else cout << 1 << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}