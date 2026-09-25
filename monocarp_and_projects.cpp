#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int x, y, k; cin >> x >> y >> k;
    int i = 0, ans = 0;

    while(y-x >= x+i && i < k) {
        ans += (y-x)%(x+i);
        i++;
    }

    ans += (k-i)*(y-x);

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