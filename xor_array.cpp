#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, l, r; cin >> n >> l >> r;
    l--, r--;

    vector<int> ans(n);
    set<int> prev = {0};

    int cur = 0;

    for(int i = 0; i < l; i++) {
        for(int j = 1; j <= 1e9; j++) {
            if(prev.find(cur^j) == prev.end()) {
                cur ^= j;
                ans[i] = j;
                prev.insert(cur);
                break;
            }
        }
    }

    int save = cur;

    for(int i = l; i < r; i++) {
        for(int j = 1; j <= 1e9; j++) {
            if(prev.find(cur^j) == prev.end()) {
                ans[i] = j;
                cur ^= j;
                prev.insert(cur);
                break;
            }
        }
    }

    ans[r] = (save^cur);
    cur = save;

    for(int i = r+1; i < n; i++) {
        for(int j = 1; j <= 1e9; j++) {
            if(prev.find(cur^j) == prev.end()) {
                ans[i] = j;
                cur ^= j;
                prev.insert(cur);
                break;
            }
        }
    }

    for(int x: ans) cout << x << ' ';
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