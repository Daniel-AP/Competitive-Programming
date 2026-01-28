#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k; cin >> n >> k;

    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;

    int l = -2e9, r = 2e9, mid, ans;

    while(l <= r) {

        mid = l+(r-l)/2;

        int cur = 0;

        for(int i = 0; i < n; i++) {
            cur += max(min(a[i].second, mid-1)-a[i].first+1, 0LL);
        }

        if(cur <= k) {
            ans = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }

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