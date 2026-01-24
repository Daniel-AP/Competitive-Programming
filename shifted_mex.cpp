#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(all(a));

    int ans = 1, cur = 1;

    for(int i = 0; i+1 < n; i++) {
        if(a[i+1]-a[i] == 1) {
            cur++;
        } else if(a[i+1]-a[i] > 1) {
            cur = 1;
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