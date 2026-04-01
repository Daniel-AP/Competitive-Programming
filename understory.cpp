#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int q; cin >> q;

    map<int, int> mp;
    int tot = 0;

    while(q--) {
        int op, h; cin >> op >> h;
        if(op == 1) {
            mp[h]++;
            tot++;
        } else {
            for(auto& [k, cnt]: mp) {
                if(k > h) break;
                tot -= cnt;
            }
            mp.erase(mp.begin(), mp.upper_bound(h));
        }
        cout << tot << '\n';
    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}