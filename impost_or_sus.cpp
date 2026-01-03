#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    string r; cin >> r;
    int n = r.length();

    int ans = 0;

    if(r[0] == 'u') ans++, r[0] = 's';
    if(r[n-1] == 'u') ans++, r[n-1] = 's';

    vector<int> u;
    for(int i = 0; i < n; i++) {
        if(r[i] == 'u') u.push_back(i);
    }

    int m = u.size();
    int cur = 1;

    for(int i = 1; i < m; i++) {
        if(u[i-1] == u[i]-1) {
            cur++;
        } else {
            ans += cur/2;
            cur = 1;
        }
    }

    ans += cur/2;

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