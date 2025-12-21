#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> k(n);
    for(int i = 0; i < n; i++) cin >> k[i];

    multiset<int> ms;

    for(int i = 0; i < n; i++) {
        auto it = ms.upper_bound(k[i]);
        if(it == ms.end()) {
            ms.insert(k[i]);
        } else {
            ms.erase(it);
            ms.insert(k[i]);
        }
    }

    cout << ms.size() << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}