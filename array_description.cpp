#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

#define MOD 1000000007
// #define MOD 998244353

int ways(int s, int l, int r, int m) {

    int t = l;
    l = min(l, r), r = max(r, t);

    vector<vector<int>> dp(s+1, vector<int>(m+1));
    dp[1][l] = 1;

    for(int i = 2; i <= s; i++) {
        for(int j = 1; j <= m; j++) {
            dp[i][j] = dp[i-1][j];
            if(j > 0) dp[i][j] += dp[i-1][j-1];
            if(j+1 <= m) dp[i][j] += dp[i-1][j+1];
            dp[i][j] %= MOD;
        }
    }

    return dp[s][r];

}

void solve() {

    int n, m; cin >> n >> m;

    vector<int> x(n);
    for(int i = 0; i < n; i++) cin >> x[i];

    int ans = 1;

    if(count(all(x), 0) == n) {
        int anss = 0;
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= m; j++) {
                anss += ways(n, i, j, m);
                anss %= MOD;
            }
        }
        return void(cout << anss << '\n');
    }

    for(int i = 0; i+1 < n; i++) {
        if(x[i] == 0 || x[i+1] == 0) continue;
        if(abs(x[i]-x[i+1]) > 1) return void(cout << 0 << '\n');
    }

    int l = 0, r = n-1;

    while(l < n && x[l] == 0) l++;

    if(x[0] == 0) {
        int t = 0;
        for(int i = 1; i <= m; i++) {
            t += ways(l+1, i, x[l], m);
            t %= MOD;
        }
        if(t == 0) {
            return void(cout << 0 << '\n');
        }
        ans *= t;
        ans %= MOD;
    }

    while(r > l && x[r] == 0) r--;

    if(x[n-1] == 0) {
        int t = 0;
        for(int i = 1; i <= m; i++) {
            t += ways(n-r, i, x[r], m);
            t %= MOD;
        }
        if(t == 0) {
            return void(cout << 0 << '\n');
        }
        ans *= t;
        ans %= MOD;
    }

    while(l < r) {
        if(x[l+1] == 0) {
            int t = l;
            l++;
            while(x[l] == 0) l++;
            ans *= ways(l-t+1, x[t], x[l], m);
            ans %= MOD;
        } else {
            l++;
        }
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