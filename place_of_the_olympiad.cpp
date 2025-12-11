#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int n, m, k; cin >> n >> m >> k;
    int l = (k+n-1)/n, o = m-l;

    cout << max((l+o)/(o+1), 1LL) << endl;
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) {
        solve();
    }

    return 0;

}