#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

#define MOD 1000000007
// #define MOD 998244353

const int N = 1000005;

int dp[N][2];

void pre() {

    dp[1][0] = 1, dp[1][1] = 1;

    for(int i = 2; i < N; i++) {
        dp[i][0] = (2*dp[i-1][0]+dp[i-1][1])%MOD;
        dp[i][1] = (dp[i-1][0]+4*dp[i-1][1])%MOD;
    }

}

void solve() {

    int n; cin >> n;

    cout << (dp[n][0]+dp[n][1])%MOD << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    pre();

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}