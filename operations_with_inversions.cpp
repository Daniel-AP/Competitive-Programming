#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n), used(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int ans = 0;

    for(int i = n-1; i >= 0; i--) {
        for(int j = i+1; j < n; j++) {
            if(a[i] > a[j] && !used[j]) {
                used[j] = 1;
                ans++;
            }
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