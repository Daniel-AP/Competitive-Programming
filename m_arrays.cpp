#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, m; cin >> n >> m;

    vector<int> a(n), b(m);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        b[a[i]%m]++;
    }

    int ans = 0;

    for(int i = 0; i <= (m-i)%m; i++) {
        if(b[i] > 0 || b[(m-i)%m] > 0) ans += max(abs(b[i]-b[(m-i)%m]), 1LL);
    }

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}