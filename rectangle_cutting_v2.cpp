#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int a, b; cin >> a >> b;

    vector<vector<int>> dp(a+1, vector<int>(b+1, INF));

    for(int i = 1; i <= a; i++) {
        for(int j = 1; j <= b; j++) {
            if(i == j) dp[i][j] = 0;
            else {
                for(int l = 1; l < i; l++) dp[i][j] = min(dp[i][j], dp[l][j]+dp[i-l][j]+1);
                for(int l = 1; l < j; l++) dp[i][j] = min(dp[i][j], dp[i][l]+dp[i][j-l]+1);
            }
        }
    }

    cout << dp[a][b] << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}