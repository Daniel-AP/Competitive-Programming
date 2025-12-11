#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n; cin >> n;

        int a, b, c;

        for(int i = 2; i < n-1; i++) {
            if(gcd(i, n-1-i) == 1) {
                a = i, b = n-1-i, c = 1;
                break;
            }
        }

        cout << a << " " << b << " " << c << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}