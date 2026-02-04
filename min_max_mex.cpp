#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k; cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int l = 0, r = 2e5, mid, ans = 0;
    
    while(l <= r) {

        mid = l+(r-l)/2;

        int q = 0, cnt = 0, id = 1;

        vector<int> has(mid+1);

        for(int i = 0; i < n; i++) {
            if(a[i] <= mid && has[a[i]] != id) cnt++, has[a[i]] = id;
            if(cnt == mid+1) q++, cnt = 0, id++;
        }

        if(q >= k) {
            ans = mid+1;
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
    cin >> t;

    while(t--) solve();

    return 0;

}