#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, x, y; cin >> n >> x >> y;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    map<pair<int, int>, int> mod;

    int ans = 0;

    for(int i = 0; i < n; i++) {

        ans += mod[{(x-a[i]%x)%x, a[i]%y}];
        mod[{a[i]%x, a[i]%y}]++;

    }

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}