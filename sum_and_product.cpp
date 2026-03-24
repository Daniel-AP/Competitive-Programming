#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    map<int, int> cnt;
    
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        cnt[x]++;
    }

    int q; cin >> q;

    while(q--) {

        int x, y; cin >> x >> y;
        int ans = 0;
        int d = x*x-4*y;

        if(d < 0) { cout << 0 << ' '; continue; }

        int sqd = (int)sqrt(d);

        if(sqd*sqd != d) { cout << 0 << ' '; continue; }

        if(abs(sqd+x)%2 != 0) { cout << 0 << ' '; continue; }

        int x1 = (sqd+x)/2, x2 = (-sqd+x)/2;
        int p1, p2;

        if(x1 == x-x1) {
            ans += cnt[x1]*(cnt[x1]-1)/2;
            p1 = x1, p2 = x1;
        } else {
            ans += cnt[x1]*(cnt[x-x1]);
            p1 = x1, p2 = x-x1;
        }

        if(x2 != x1) {
            if(x2 == x-x2 && (p2 != x2 || p1 != x2)) {
                ans += cnt[x2]*(cnt[x2]-1);
            } else if(p2 != x2 || p1 != x-x2) {
                ans += cnt[x2]*(cnt[x-x2]);
            }
        }

        cout << ans << ' ';

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