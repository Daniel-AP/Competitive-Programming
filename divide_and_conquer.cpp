#include <bits/stdc++.h>
using namespace std;

#define int long long

int l(int n) {

    int c = 0;
    int m = 1-n%2;

    while(n != m) {
        n /= 2;
        c++;
        if(n%2 == m) break;
    }

    return c;

}

void solve() {

    int t; cin >> t;

    while(t--) {

        int n; cin >> n;

        vector<int> a(n);
        int s = 0;
        int m = 1e9;

        for(int i = 0; i < n; i++) {

            cin >> a[i];
            s += a[i];

            m = min(l(a[i]), m);

        }

        if(s%2 == 0) cout << 0 << endl;
        else cout << m << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}