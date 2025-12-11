#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i += 2) a[i] = -a[i];

    set<int> prev = {0};
    int cur = 0;

    for(int i = 0; i < n; i++) {
        cur += a[i];
        if(prev.find(cur) != prev.end()) return void(cout << "YES" << '\n');
        prev.insert(cur);
    }

    cout << "NO" << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}