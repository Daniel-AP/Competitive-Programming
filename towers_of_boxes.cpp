#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, m, d; cin >> n >> m >> d;

    if(d/m == 0) return void(cout << n << '\n');
    else {
        int ans = 0;
        while(n > 0) {
            ans++;
            n -= d/m+1;
        }
        cout << ans << '\n';
    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}