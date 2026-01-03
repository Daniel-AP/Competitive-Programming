#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> x(n-1);
    for(int i = 0; i < n-1; i++) cin >> x[i];

    int cur = 0, b = 1e8;

    cout << b << ' ';

    for(int i = 0; i < n-1; i++) {
        cur += x[i];
        cout << b+cur << ' ';
    }

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