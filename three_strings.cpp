#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    string a, b, c; cin >> a >> b >> c;
    int n1 = a.length(), n2 = b.length(), n3 = n1+n2;

    vector<vector<int>> dp(n1+1, vector<int>(n2+1, INF));

    dp[0][0] = 0;

    for(int i = 1; i <= n1; i++) {
        dp[i][0] = dp[i-1][0]+(a[i-1]!=c[i-1]);
    }

    for(int i = 1; i <= n2; i++) {
        dp[0][i] = dp[0][i-1]+(b[i-1]!=c[i-1]);
    }

    for(int i = 1; i <= n1; i++) {
        for(int j = 1; j <= n2; j++) {
            if(i-1 >= 0) dp[i][j] = dp[i-1][j]+(a[i-1]!=c[i+j-1]);
            if(j-1 >= 0) dp[i][j] = min(dp[i][j], dp[i][j-1]+(b[j-1]!=c[i+j-1]));
        }
    }

    int ans = n3;

    for(int i = 1; i <= n1; i++) {
        if(n3-i > n2) continue;
        ans = min(ans, dp[i][n3-i]);
    }

    for(int i = 1; i <= n2; i++) {
        if(n3-i > n1) continue;
        ans = min(ans, dp[n3-i][i]);
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