#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k, z; cin >> n >> k >> z;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int ans = 0;
    for(int i = 0; i <= k; i++) ans += a[i];

    vector<int> mx(n);
    mx[1] = a[0]+a[1];
    for(int i = 2; i < n; i++) mx[i] = max(mx[i-1], a[i-1]+a[i]);

    vector<int> px(n);
    px[0] = a[0];
    for(int i = 1; i < n; i++) px[i] = px[i-1]+a[i];

    for(int i = 1; i <= z; i++) {
        int end = 1+(k-i)-i;
        if(end <= 0) break;
        ans = max(ans, px[end-1]+mx[end-1]*i);
        if(end < n) {
            ans = max(ans, px[end]+a[end-1]+mx[end]*(i-1));
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