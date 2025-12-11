#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

void solve() {

    int n, x; cin >> n >> x;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int l(1), r(1e12+5), mid, ans;

    while(l <= r) {

        mid = l+(r-l)/2;
        int s = 0;

        for(int i = 0; i < n; i++) {
            s += max(mid-a[i], 0LL);
        }

        if(s <= x) {
            ans = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }

    }

    cout << ans << "\n";
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}