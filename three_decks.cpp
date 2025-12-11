#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int a, b, c; cin >> a >> b >> c;

    if(((c-b+a)-b)%3 == 0 && ((c-b+a)-b) >= 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}