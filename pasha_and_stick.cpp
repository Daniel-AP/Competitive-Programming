#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int n; cin >> n;

    if(n%2 == 1) {
        cout << 0 << endl;
    } else {
        cout << n/4-(n%4==0) << endl;
    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}