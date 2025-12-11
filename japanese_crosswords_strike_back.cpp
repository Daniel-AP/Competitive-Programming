#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

void solve() {

    int n, x; cin >> n >> x;
    int s = 0;

    for(int i = 0; i < n; i++) {
        int k; cin >> k;
        s += k;
    }

    if(s+n-1 == x) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; t = 1;

    while(t--) solve();

    return 0;

}