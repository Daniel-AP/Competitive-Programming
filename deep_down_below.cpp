#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<pair<int, int>> p;

    for(int i = 0; i < n; i++) {
        int k; cin >> k;
        vector<int> a(k);
        for(int j = 0; j < k; j++) cin >> a[j];
        int l = 1, r = 1e10, mid, ans;
        while(l <= r) {
            mid = l+(r-l)/2;
            bool good = true;
            for(int j = 0; j < k; j++) {
                if(mid+j <= a[j]) {
                    good = false;
                    break;
                }
            }
            if(good) {
                ans = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        p.push_back({ ans, k });
    }

    sort(p.begin(), p.end(), [&](pair<int, int> p1, pair<int, int> p2) {
        if(p1.first != p2.first) return p1.first < p2.first;
        return p1.second > p2.second;
    });

    int ans = p[0].first, cur = p[0].first;

    for(int i = 0; i+1 < p.size(); i++) {
        cur += p[i].second;
        ans += max(p[i+1].first-cur, 0LL);
        cur += max(p[i+1].first-cur, 0LL);
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