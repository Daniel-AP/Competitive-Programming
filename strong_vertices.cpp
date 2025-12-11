#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n), b(n);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    int mx = -INF;
    for(int i = 0; i < n; i++) mx = max(mx, a[i]-b[i]);
    
    vector<int> ans;

    for(int i = 0; i < n; i++) {
        if(a[i]-b[i] == mx) {
            ans.push_back(i+1);
        }
    }

    cout << ans.size() << '\n';

    for(int x: ans) cout << x << ' ';
    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}