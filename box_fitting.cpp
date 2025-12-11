#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, w; cin >> n >> w;

    multiset<int> ms;

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        ms.insert(x);
    }

    int s = w, ans = 1;

    while(!ms.empty()) {

        auto it = ms.lower_bound(s);

        if(it == ms.end()) it--;
        if(*it > s) {
            if(it == ms.begin()) {
                s = w;
                ans++;
                continue;
            } else {
                it--;
            }
        }

        s -= *it;

        ms.erase(it);

    }

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