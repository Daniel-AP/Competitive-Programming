#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int l, r, d, u; cin >> l >> r >> d >> u;
    int ans = 0;

    for(int x = l; x <= r; x++) {
        int xx = abs(x);
        if(xx%2) continue;
        int lb = max(d, -xx+1), rb = min(u, xx-1);
        if(lb > rb) continue;
        ans += rb-lb+1;
    }

    for(int y = d; y <= u; y++) {
        int yy = abs(y);
        if(yy%2) continue;
        int lb = max(l, -yy+1), rb = min(r, yy-1);
        if(lb > rb) continue;
        ans += rb-lb+1;
    }

    for(int x = l; x <= r; x++) {
        int xx = abs(x);
        if(xx%2) continue;
        if(-xx >= d && -xx <= u) ans++;
        if(-xx == xx) continue;
        if(xx >= d && xx <= u) ans++;
    }

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}