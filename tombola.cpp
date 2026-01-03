#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int h, w, n; cin >> h >> w >> n;

    vector<vector<int>> a(h, vector<int>(w));

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin >> a[i][j];
        }
    }

    vector<bool> has(90+1);

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        has[x] = 1;
    }

    int ans = 0;

    for(int i = 0; i < h; i++) {
        int cur = 0;
        for(int j = 0; j < w; j++) {
            if(has[a[i][j]]) cur++;
        }
        ans = max(cur, ans);
    }

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}