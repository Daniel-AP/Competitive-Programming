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

    int mx = -INF;

    for(int i = 0; i < n; i++) {
        int cur = 0;
        if(i > 0) cur += abs(a[i-1]-a[i]);
        if(i+1 < n) cur += abs(a[i]-a[i+1]);
        if(i > 0 && i+1 < n) cur -= abs(a[i-1]-a[i+1]);
        mx = max(mx, cur);
    }

    int s = 0;

    for(int i = 0; i+1 < n; i++) {
        s += abs(a[i]-a[i+1]);
    }

    cout << s-mx << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}