#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int ans = a[0], cur = a[0];

    for(int i = 1; i < n; i++) {

        if(cur+a[i] >= a[i] && abs(a[i-1])%2 != abs(a[i])%2) {
            cur += a[i];
        } else {
            cur = a[i];
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