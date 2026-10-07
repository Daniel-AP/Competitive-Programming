#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n+1), b(n+1);

    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];

    vector<int> full(n+1);

    for(int i = 1; i <= n; i++) {
        full[i] = full[i-1];
        if(i > 1) full[i] += (b[i-1] == a[i] ? 2 : 1);
        full[i] += (a[i] == b[i] ? 2: 1);
    }

    vector<int> zz(n+1);
    zz[n] = (a[n] == b[n] ? 2 : 1);

    for(int i = n-1; i >= 1; i--) {
        zz[i] = zz[i+1];
        zz[i] += (a[i] == b[i+1] ? 2 : 1);
        zz[i] += (b[i] == a[i+1] ? 2 : 1);
    }

    int ans = full[n];

    for(int i = 1; i <= n; i++) {
        ans = max(ans, full[i]-(a[i] == b[i] ? 2: 1)+zz[i]);
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