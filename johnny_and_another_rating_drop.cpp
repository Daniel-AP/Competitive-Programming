#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;
    int ans = 0, cur = 2;

    while(n >= cur) {
        ans += n/cur;
        cur *= 2;
    }

    cout << ans+n << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}