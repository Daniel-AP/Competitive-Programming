#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<double> a(n), t(n);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> t[i];

    double mn = INF;
    for(int i = 0; i < n; i++) mn = min(mn, t[i]);

    double l = mn, r = 1e12, mid, ans;

    for(int i = 0; i < 100; i++) {
        
        mid = l+(r-l)/2;
        double ll = 0, rr = 1e12;
        
        for(int i = 0; i < n; i++) {
            ll = max(ll, a[i]-mid+t[i]);
            rr = min(rr, a[i]+mid-t[i]);
        }

        if(ll <= rr) {
            ans = (rr+ll)/2;
            r = mid;
        } else {
            l = mid;
        }

    }

    cout << fixed << setprecision(9) << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}