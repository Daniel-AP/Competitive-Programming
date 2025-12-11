#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, x, y; cin >> n >> x >> y;
    int l = n/lcm(x, y);
    int m1 = n/y-l, m2 = n/x-l;
    int ans = 0;

    ans -= m1*(m1+1)/2;
    ans += m2*(n+(n-m2+1))/2;

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}