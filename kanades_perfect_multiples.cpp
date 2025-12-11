#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k; cin >> n >> k;

    set<int> a, b, good;

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        a.insert(x);
    }

    while(!a.empty()) {
        int x = *a.begin();
        b.insert(x);
        for(int i = x; i <= k; i += x) {
            if(a.find(i) == a.end() && good.find(i) == good.end()) return void(cout << -1 << '\n');
            a.erase(i);
            good.insert(i);
        }
    }

    cout << b.size() << '\n';
    for(int x: b) cout << x << ' ';
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