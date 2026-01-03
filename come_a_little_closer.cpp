#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

using pp = pair<int, int>;

void solve() {

    int n; cin >> n;

    vector<pp> mons(n);
    for(int i = 0; i < n; i++) cin >> mons[i].first >> mons[i].second;

    if(n == 1) return void(cout << 1 << '\n');

    vector<pp> left = mons, right = mons, up = mons, down = mons;

    sort(left.begin(), left.end(), [&](pp p1, pp p2) { return p1.second < p2.second; });
    sort(right.begin(), right.end(), [&](pp p1, pp p2) { return p1.second > p2.second; });
    sort(up.begin(), up.end(), [&](pp p1, pp p2) { return p1.first < p2.first; });
    sort(down.begin(), down.end(), [&](pp p1, pp p2) { return p1.first > p2.first; });

    int ans = INF;

    for(int i = 0; i < n; i++) {

        int mxl, mxr, mxu, mxd;

        if(left[0] == mons[i]) mxl = left[1].second;
        else mxl = left[0].second;
        if(right[0] == mons[i]) mxr = right[1].second;
        else mxr = right[0].second;
        if(up[0] == mons[i]) mxu = up[1].first;
        else mxu = up[0].first;
        if(down[0] == mons[i]) mxd = down[1].first;
        else mxd = down[0].first;

        int cur = (mxr-mxl+1)*(mxd-mxu+1);

        if(cur < n) {
            if((mxr-mxl+1) > (mxd-mxu+1)) cur = (mxr-mxl+2)*(mxd-mxu+1);
            else cur = (mxr-mxl+1)*(mxd-mxu+2);
        }

        ans = min(ans, cur);

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