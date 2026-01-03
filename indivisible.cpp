#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    if(n == 1) return void(cout << 1 << '\n');
    if(n%2) return void(cout << -1 << '\n');

    vector<int> ans(n);
    iota(ans.begin(), ans.end(), 1);

    for(int i = 2; i <= n; i += 2) {
        cout << i << ' ' << i-1 << ' ';
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