#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k; cin >> n >> k;

    vector<int> a(n), b(n);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    sort(all(b));

    int l = 0, r = 2e9, mid, t;

    while(l <= r) {

        mid = l+(r-l)/2;

        int cnt = 0;

        for(int i = 0; i < n; i++) {
            int x = mid-a[i];
            int j = lower_bound(all(b), x)-b.begin();
            cnt += j;
        }

        if(cnt+1 <= k) {
            t = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }

    }

    int ans = INF;

    for(int i = 0; i < n; i++) {
        int j = lower_bound(all(b), t-a[i])-b.begin();;
        if(j == n) continue;
        int x = b[j];
        ans = min(ans, a[i]+x);
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