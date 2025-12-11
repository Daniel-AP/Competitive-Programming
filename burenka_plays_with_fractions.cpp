#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int a, b, c, d; cin >> a >> b >> c >> d;
        int g = gcd(a, b), h = gcd(c, d);

        a /= g; b /= g;
        c /= h; d /= h;

        if(a == 0 && c == 0) cout << 0 << endl;
        else if(a == 0 || c == 0) cout << 1 << endl;
        else if((a*d)%(b*c) == 0) cout << ((a*d)/(b*c) == 1 ? 0 : 1) << endl;
        else if((c*b)%(a*d) == 0) cout << ((c*b)%(a*d) == 1 ? 0 : 1) << endl;
        else cout << 2 << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}