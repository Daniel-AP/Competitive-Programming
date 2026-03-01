#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int x, y; cin >> x >> y;

    if(y > 0) {
        if(2*y <= x && (x-2*y)%3 == 0) cout << "YES";
        else cout << "NO";
    } else {
        if(-4*y <= x && (x+4*y)%3 == 0) cout << "YES";
        else cout << "NO";
    }

    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}