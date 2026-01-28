#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k; cin >> n >> k;

    vector<double> a(n), b(n);

    for(int i = 0; i < n; i++) cin >> a[i] >> b[i];

    double l = 0, r = 1e6, mid, ans;

    for(int i = 0; i < 100; i++) {

        mid = l+(r-l)/2;

        vector<double> c(n);

        for(int j = 0; j < n; j++) {
            c[j] = a[j]-mid*b[j];
        }

        sort(c.rbegin(), c.rend());

        double cur = 0;
        for(int j = 0; j < k; j++) cur += c[j];

        if(cur >= 0) {
            ans = mid;
            l = mid;
        } else {
            r = mid;
        }

    }

    cout << fixed << setprecision(9) << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}