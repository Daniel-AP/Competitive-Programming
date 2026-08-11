#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int a, b, c; cin >> a >> b >> c;
    int ans = 0;

    while(true) {
        if(a == b || a == c || b == c) break;
        int mn = min({ a, b, c });
        int mx = max({ a, b, c });
        if(a == mx) {
            a--;
            if(b == mn) b++;
            if(c == mn) c++;
        }
        if(b == mx) {
            b--;
            if(a == mn) a++;
            if(c == mn) c++;
        }
        if(c == mx) {
            c--;
            if(b == mn) b++;
            if(a == mn) a++;
        }
        ans++;
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