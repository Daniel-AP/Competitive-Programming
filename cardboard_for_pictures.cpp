#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, c; cin >> n >> c;

    vector<int> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];

    int l = 1, r = 1e9, mid, ans;

    while(l <= r) {

        mid = l+(r-l)/2;

        int cur = 0;

        for(int i = 0; i < n; i++) {
            cur += (s[i]+2*mid)*(s[i]+2*mid);
            cur = min(cur, c);
        }

        if(cur >= c) {
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
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