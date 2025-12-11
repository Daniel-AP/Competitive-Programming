#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int n, k; cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int l(1), r(1e15), mid, ans;

    while(l <= r) {
        mid = l+(r-l)/2;
        int cnt = 1, t = 0;
        for(int i = 0; i < n; i++) {
            t += a[i];
            if(a[i] > mid) {
                cnt += k+1;
            }
            else if(t > mid) {
                cnt++;
                t = a[i];
            }
        }
        if(cnt <= k) {
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }

    cout << ans << endl;

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}