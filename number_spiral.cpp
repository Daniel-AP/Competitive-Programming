#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int y, x; cin >> y >> x;

    int mx = max(y, x);
    int ans = mx*mx;

    if(mx%2) {
        ans -= abs(y-1)+abs(x-mx);
    } else {
        ans -= abs(y-mx)+abs(x-1);
    }

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}