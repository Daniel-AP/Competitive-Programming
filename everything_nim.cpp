#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    set<int> a;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        a.insert(x);
    }

    int prev = 0, cnt = 0;

    for(int x: a) {
        if(x-prev > 1) break;
        cnt++;
        prev = x;
    }

    if(cnt == a.size()) cout << (cnt%2 ? "Alice" : "Bob") << '\n';
    else cout << (cnt%2 ? "Bob" : "Alice") << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}