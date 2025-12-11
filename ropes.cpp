#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int n, k; cin >> n >> k;

    vector<double> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    double l(1e-7), r(1e7), mid, ans(0), eps(1e-7);

    while(r-l > eps) {

        int cnt = 0;
        mid = l+(r-l)/2;

        for(int i = 0; i < n; i++) {
            cnt += (int)(a[i]/mid);
        }
        
        if (cnt >= k) {
            ans = mid;
            l = mid;
        } else {
            r = mid;
        }

    }

    cout << setprecision(7) <<  ans << endl;
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; t = 1;

    while(t--) solve();

    return 0;

}