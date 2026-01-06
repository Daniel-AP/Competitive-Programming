#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    if(count(all(a), a[0]) == n) return void(cout << 0 << '\n');
    if(find(all(a), 1) != a.end()) return void(cout << -1 << '\n');

    vector<pair<int, int>> moves;

    while(true) {
        if(count(all(a), a[0]) == n) break;
        int i = max_element(all(a))-a.begin();
        int j = min_element(all(a))-a.begin();
        a[i] = (a[i]+a[j]-1)/a[j];
        moves.push_back({ i+1, j+1 });
    }

    cout << moves.size() << '\n';

    for(auto [i, j]: moves) cout << i << ' ' << j << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}