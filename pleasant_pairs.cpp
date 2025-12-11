#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];

    int ans = 0;

    for(int i = 1; i <= n; i++) {
        int d = (i+a[i]-1)/a[i]*a[i]-i;
        for(int j = (i-d+a[i]-1)/a[i]*a[i]+d; j <= n; j += a[i]) {
            if(a[j] == (i+j)/a[i] && j > i) ans++;
        }
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