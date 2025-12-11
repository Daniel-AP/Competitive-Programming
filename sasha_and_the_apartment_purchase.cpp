#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k; cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    vector<pair<int, int>> b;

    for(int i = 0; i < n; i++) {

        if(i+1 < n) {

            int dmn = min(i, (n-1)-(i+1)), dmx = max(i, (n-1)-(i+1));

            if(dmx-dmn <= k) {
                b.push_back({ a[i], a[i+1] });
                continue;
            }

        }

        int dmn = min(i, (n-1)-i), dmx = max(i, (n-1)-i);

        if(dmx-dmn <= k) {
            b.push_back({ a[i], a[i] });
        }

    }

    int l = b[0].first, r = b[0].second, ans = 0;

    for(int i = 0; i < b.size(); i++) {
        
        int inter = min(r, b[i].second)-max(l, b[i].first);

        if(inter >= 0) {
            l = min(l, b[i].first), r = max(r, b[i].second);
        } else {
            ans += r-l+1;
            l = b[i].first, r = b[i].second;
        }

    }

    ans += r-l+1;

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