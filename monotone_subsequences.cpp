#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k; cin >> n >> k;

    if((n+k-1)/k > k) return void(cout << "IMPOSSIBLE" << '\n');

    vector<int> p(n);
    iota(all(p), 1);

    for(int i = 0; i+k-1 < n; i += k) {
        reverse(p.begin()+i, p.begin()+i+k);
    }

    if(n%k != 0) reverse(p.end()-n%k, p.end());

    for(int x: p) cout << x << ' ';
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