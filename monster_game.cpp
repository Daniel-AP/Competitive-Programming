#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n), b(n);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    sort(all(a));

    vector<int> px(n);
    px[0] = b[0];

    for(int i = 1; i < n; i++) px[i] = px[i-1]+b[i];

    int ans = 0;

    for(int i = 0; i < n; i++) {
        int lvl = upper_bound(all(px), n-i)-px.begin();
        ans = max(ans, lvl*a[i]);
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