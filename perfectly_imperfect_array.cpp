#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t;
    cin >> t;

    while(t--) {

        int n; cin >> n;
        string ans = "NO";

        for(int i = 0; i < n; i++) {
            int a; cin >> a;
            int b = sqrt(a);
            if(b*b != a) ans = "YES";
        }

        cout << ans << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}