#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;
    int cur = 2*n-1;

    vector<array<int, 2>> ans(n);

    for(int i = 0; i < n; i++) {
        if(i%2 == 0) {
            ans[i][0] = cur--;
        } else {
            ans[i][1] = cur--;
        }
    }

    cur++;

    for(int i = 0; i < n; i++) {
        if(i%2 == 0) {
            ans[i][1] = cur--;
        } else {
            ans[i][0] = cur--;
        }
    }

    ans[n-1][1] = 2*n;

    for(int i = 0; i < n; i++) cout << ans[i][0] << ' ';
    cout << '\n';
    for(int i = 0; i < n; i++) cout << ans[i][1] << ' ';
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