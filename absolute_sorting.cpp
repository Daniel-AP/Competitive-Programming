#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int l = 0, r = 1e9;

    for(int i = 0; i+1 < n; i++) {
        if(a[i] == a[i+1]) continue;
        if(a[i] < a[i+1]) r = min(r, (a[i]+a[i+1])/2);
        else l = max(l, (a[i]+a[i+1]+1)/2);
    }

    if(l > r) cout << -1 << '\n';
    else cout << l << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}