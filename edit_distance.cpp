#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    string s1, s2; cin >> s1 >> s2;
    int n = s1.length(), m = s2.length();

    vector<vector<int>> dp(n, vector<int>(m));

    for(int i = n-1; i >= 0; i--) {
        for(int j = m-1; j >= 0; j--) {
            if(i+1 == n && j+1 == m) {
                dp[i][j] = (s1[i]!=s2[j]);
            } else if(i+1 == n) {
                dp[i][j] = min((m-j-1)+(s1[i]!=s2[j]), dp[i][j+1]+1);
            } else if(j+1 == m) {
                dp[i][j] = min((n-i-1)+(s1[i]!=s2[j]), dp[i+1][j]+1);
            } else {
                dp[i][j] = min({dp[i+1][j+1]+(s1[i]!=s2[j]), dp[i][j+1]+1, dp[i+1][j]+1});
            }
        }
    }

    cout << dp[0][0] << '\n';
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}