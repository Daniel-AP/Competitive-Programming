#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, ax, ay, bx, by; cin >> n >> ax >> ay >> bx >> by;

    vector<pair<int, int>> xy(n);

    for(int i = 0; i < n; i++) cin >> xy[i].first;
    for(int i = 0; i < n; i++) cin >> xy[i].second;

    map<int, int> mp0, mp1;

    for(int i = 0; i < n; i++) {
        if(mp0.find(xy[i].first) == mp0.end()) mp0[xy[i].first] = xy[i].second;
        else mp0[xy[i].first] = min(mp0[xy[i].first], xy[i].second);
        if(mp1.find(xy[i].first) == mp1.end()) mp1[xy[i].first] = xy[i].second;
        else mp1[xy[i].first] = max(mp1[xy[i].first], xy[i].second);
    }

    map<int, array<int, 2>> dp;

    dp[ax][0] = 0, dp[ax][1] = 0;

    int prevx = ax, prevy0 = ay, prevy1 = ay;
    int x, y0, y1;

    for(auto& [k, _]: mp0) {
        x = k, y0 = mp0[x], y1 = mp1[x];
        dp[k][0] = min(dp[prevx][0]+abs(prevx-x)+abs(prevy0-y1), dp[prevx][1]+abs(prevx-x)+abs(prevy1-y1))+abs(y0-y1);
        dp[k][1] = min(dp[prevx][0]+abs(prevx-x)+abs(prevy0-y0), dp[prevx][1]+abs(prevx-x)+abs(prevy1-y0))+abs(y0-y1);
        prevx = x, prevy0 = y0, prevy1 = y1;
    }

    cout << min(dp[prevx][0]+abs(prevx-bx)+abs(prevy0-by), dp[prevx][1]+abs(prevx-bx)+abs(prevy1-by)) << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}