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

    for(int i = 1; i < n-1; i++) {
        if(a[i] == -1) a[i] = 0;
    }

    int s = 0;

    for(int i = 0; i < n-1; i++) {
        if(a[i+1] != -1 && a[i] != -1) {
            s += a[i+1]-a[i];
        }
    }

    bool can = a[0] == -1 && a[n-1] == -1;

    if(a[0] == -1) {
        if(s > 0) a[0] = a[1]+s, s = 0;
        else if(s < 0) a[0] = a[1]-min(-s, a[1]), s += min(-s, a[1]);
        else a[0] = a[1];
    }

    if(a[n-1] == -1) {
        if(s < 0) a[n-1] = a[n-2]-s, s = 0;
        else if(s > 0) a[n-1] = a[n-2]-min(s, a[n-2]), s -= min(s, a[n-2]);
        else a[n-1] = a[n-2];
    }

    int mn = min(a[0], a[n-1]);

    if(can) a[0] -= mn, a[n-1] -= mn;

    cout << abs(s) << '\n';
    for(int x: a) cout << x << ' ';
    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}