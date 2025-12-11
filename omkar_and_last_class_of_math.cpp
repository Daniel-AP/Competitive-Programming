#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;
    int ans1 = INF, ans2 = INF;

    for(int i = 1; i*i <= n; i++) {
        if(n%i != 0) continue;
        int k1 = n/i-1, k2 = n/(n/i)-1;
        if(lcm(ans1, ans2) > lcm(i, i*k1) && i > 0 && k1 > 0) ans1 = i, ans2 = i*k1;
        if(lcm(ans1, ans2) > lcm(n/i, n/i*k2) && n/i > 0 && k2 > 0) ans1 = n/i, ans2 = n/i*k2;
    }

    cout << ans1 << ' ' << ans2 << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}