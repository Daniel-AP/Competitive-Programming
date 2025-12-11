#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k; cin >> n >> k;

    vector<int> a(n), b(n);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    vector<int> px(n), sx(n);
    px[0] = a[0], sx[n-1] = a[n-1];

    for(int i = 1; i < n; i++) {
        px[i] = max(a[i], px[i-1]+a[i]);
    }

    for(int i = n-2; i >= 0; i--) {
        sx[i] = max(a[i], sx[i+1]+a[i]);
    }

    int ans = *max_element(px.begin(), px.end());

    if(k%2 == 0) return void(cout << ans << '\n');

    for(int i = 0; i < n; i++) {
        ans = max(ans, px[i]+sx[i]-a[i]+b[i]);
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