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

    int ans = a[n-1];

    for(int i = 0; i < n-1; i++) {

        int l = a[i], r = a[i]+k, mid, cur = a[i];

        while(l <= r) {

            mid = l+(r-l)/2;
            int has = k-(mid-a[i]), prev = mid;
            bool good = has >= 0;

            for(int j = i+1; j < n; j++) {
                if(a[j] >= prev-1) break;
                if(has < prev-1-a[j]) { good = false; break; }
                if(j == n-1) { good = false; break; }
                has -= prev-1-a[j];
                prev = prev-1;
            }

            if(good) {
                cur = mid;
                l = mid+1;
            } else {
                r = mid-1;
            }

        }

        ans = max(ans, cur);

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