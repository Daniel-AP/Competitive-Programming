#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, q; cin >> n >> q;
    string s; cin >> s;

    vector<int> a(q);
    for(int i = 0; i < q; i++) cin >> a[i];

    if(s == string(n, 'A')) {
        for(int i = 0; i < q; i++) cout << a[i] << '\n';
        return;
    }

    for(int i = 0; i < q; i++) {

        int l = 1, r = 1e3, mid, ans;

        while(l <= r) {

            mid = l+(r-l)/2;
            int m = a[i];

            for(int j = 0; j < mid; j++) {
                if(s[j%n] == 'A') {
                    m--;
                } else {
                    m /= 2;
                }
            }

            if(m <= 0) {
                ans = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }

        }

        cout << ans << '\n';

    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}