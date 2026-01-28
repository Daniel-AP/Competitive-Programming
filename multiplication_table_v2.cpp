#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k; cin >> n >> k;
    int l = 1, r = n*n, mid, t;

    while(l <= r) {

        mid = l+(r-l)/2;

        int cnt = 0;

        for(int i = 1; i <= n; i++) {
            if(mid%i == 0) cnt += min(mid/i-1, n);
            else cnt += min(mid/i, n);
        }

        if(cnt+1 <= k) {
            t = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }

    }

    int ans = INF;

    for(int i = 1; i <= n; i++) {
        int x = (t+i-1)/i;
        ans = min(i*x, ans);
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