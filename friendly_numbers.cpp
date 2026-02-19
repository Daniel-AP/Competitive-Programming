#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

int d(int n) {
    int ans = 0;
    while(n) ans += n%10, n /= 10;
    return ans;
}

void solve() {

    int x; cin >> x;
    int ans = 0;

    for(int i = 0; i <= 81; i++) {
        if(d(i+x) == i) ans++;
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