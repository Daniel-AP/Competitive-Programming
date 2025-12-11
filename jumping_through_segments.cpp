#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<pair<int, int>> lr(n);
    for(auto& p: lr) cin >> p.first >> p.second;

    int l = 0, r = 1e10, k, ans;

    while(l <= r) {

        k = l+(r-l)/2;

        bool good = true;
        pair<int, int> seg = { 0, 0 };

        for(int i = 0; i < n; i++) {
            seg.first -= k, seg.second += k;
            int inter = min(lr[i].second, seg.second)-max(lr[i].first, seg.first);
            if(inter < 0) good = false;
            seg.first = max(lr[i].first, seg.first), seg.second = min(lr[i].second, seg.second);
        }

        if(good) {
            ans = k;
            r = k-1;
        } else {
            l = k+1;
        }

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