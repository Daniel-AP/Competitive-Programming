#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n), b(n);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    map<int, int> mpa, mpb;

    int cur = 1;

    for(int i = 1; i < n; i++) {
        if(a[i-1] != a[i]) {
            mpa[a[i-1]] = max(mpa[a[i-1]], cur);
            cur = 1;
        } else {
            cur++;
        }
    }

    mpa[a[n-1]] = max(mpa[a[n-1]], cur);
    cur = 1;

    for(int i = 1; i < n; i++) {
        if(b[i-1] != b[i]) {
            mpb[b[i-1]] = max(mpb[b[i-1]], cur);
            cur = 1;
        } else {
            cur++;
        }
    }

    mpb[b[n-1]] = max(mpb[b[n-1]], cur);

    int ans = 0;

    for(int i = 1; i <= 2*n; i++) {
        ans = max(ans, mpa[i]+mpb[i]);
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