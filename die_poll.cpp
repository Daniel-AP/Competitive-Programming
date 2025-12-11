#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int y, w; cin >> y >> w;

    int r = 6-max(y, w)+1;
    int n = 6;
    int g = gcd(r, n);

    r /= g;
    n /= g;

    cout << r << "/" << n << endl;

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}