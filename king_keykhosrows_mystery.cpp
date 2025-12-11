#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int a, b; cin >> a >> b;

        cout << lcm(a, b) << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}