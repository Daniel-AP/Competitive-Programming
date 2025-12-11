#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n, m; cin >> n >> m;

        int s = 0;
        for(int i = 0; i < m; i++) {
            int x; cin >> x;
            s += x;
        }

        cout << s/n+(s%n!=0) << " " << s/n << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}