#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k, q; cin >> n >> k >> q;

    vector<pair<int, int>> c1, c2;

    for(int i = 0; i < q; i++) {
        int c, l, r; cin >> c >> l >> r;
        if(c == 1) c1.push_back({ l-1, r-1 });
        else c2.push_back({ l-1, r-1 });
    }

    set<int> hasC2;

    for(auto [l, r]: c2) {
        for(int i = l; i <= r; i++) hasC2.insert(i);
    }

    vector<int> ans(n, -1);

    for(auto [l, r]: c1) {
        for(int i = l; i <= r; i++) {
            if(hasC2.find(i) == hasC2.end()) {
                ans[i] = k;
            } else {
                ans[i] = 1e9;
            }
        }
    }

    vector<pair<int, int>> cc2;

    sort(c2.begin(), c2.end());

    int l = -1, r = -1;
    if(!c2.empty()) l = c2[0].first, r = c2[0].second;

    for(int i = 0; i < c2.size(); i++) {
        int inter = min(c2[i].second, r)-max(c2[i].first, l);
        if(inter >= 0) l = min(c2[i].first, l), r = max(c2[i].second, r);
        else {
            cc2.push_back({ l, r });
            l = c2[i].first, r = c2[i].second;
        }
    }

    if(l != -1 && r != -1) cc2.push_back({ l, r });

    for(auto [l, r]: cc2) {
        int cur = 0;
        for(int i = l; i <= r; i++) {
            if(ans[i] != -1) continue;
            ans[i] = cur%k;
            cur++;
        }
    }

    for(int x: ans) cout << (x != -1 ? x : (int)(1e9)) << ' ';
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