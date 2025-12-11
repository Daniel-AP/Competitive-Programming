#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int a, b; cin >> a >> b;

        string ans = "NO";

        if(a%2 == 0 && min(a/2, b*2) != min(a, b)) ans = "YES";
        if(b%2 == 0 && min(b/2, a*2) != min(a, b)) ans = "YES";

        cout << ans << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}