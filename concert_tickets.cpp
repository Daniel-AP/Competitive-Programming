#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, m; cin >> n >> m;

    multiset<int> h;

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        h.insert(x);
    }

    for(int i = 0; i < m; i++) {
        int x; cin >> x;
        auto it = h.upper_bound(x);
        if(it == h.begin()) cout << -1 << '\n';
        else {
            it--;
            cout << *it << '\n';
            h.erase(it);
        }
    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}