#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int m, n; cin >> m >> n;

    vector<tuple<int, int, int>> k(n);

    for(int i = 0; i < n; i++) {
        int t, z, y; cin >> t >> z >> y;
        k[i] = { t, z, y };
    }

    int l(0), r(1e9), mid, ans;

    vector<int> a;

    while(l <= r) {

        mid = l+(r-l)/2;

        int balloons = 0;

        vector<int> q(n);
        
        for(int i = 0; i < n; i++) {
            int t = get<0>(k[i]), z = get<1>(k[i]), y = get<2>(k[i]);
            balloons += mid/(t*z+y)*z; balloons += min(mid%(t*z+y)/t, z);
            q[i] = mid/(t*z+y)*z+min(mid%(t*z+y)/t, z);
        }

        if(balloons >= m) {
            ans = mid;
            a = q;
            r = mid-1;
        } else {
            l = mid+1;
        }

    }

    int s = 0;
    for(int i: a) s += i;

    if(s > m) {
        for(int i = 0; i < n; i++) {
            int v = min(a[i], s-m);
            a[i] -= v;
            s -= v;
        } 
    }

    cout << ans << "\n";
 
    for(int i: a) cout << i << " ";
    cout << "\n";

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; t = 1;

    while(t--) solve();

    return 0;

}