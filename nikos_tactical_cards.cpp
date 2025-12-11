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

    int mx = 0, mn = 0;

    for(int i = 0; i < n; i++) {
        int t1 = mx, t2 = mn;
        mx = max(t1-a[i], b[i]-t2);
        mn = min(t2-a[i], b[i]-t1);
    }

    cout << mx << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}