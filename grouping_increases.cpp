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

    int s = INF, t = INF, ans = 0;

    for(int i = 0; i < n; i++) {
        bool b1 = s >= a[i], b2 = t >= a[i];
        if(b1 && b2) {
            if(s < t) s = a[i];
            else t = a[i];
        } else if(b1) {
            s = a[i];
        } else if(b2) {
            t = a[i];
        } else {
            ans++;
            if(s < t) s = a[i];
            else t = a[i];
        }
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