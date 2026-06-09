#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

vector<int> pfun(const string& s) {
    int n = (int)s.size(), j = 0;
    vector<int> pi(n);

    for(int i = 1; i < n; i++) {
        while(j > 0 && s[i] != s[j]) j = pi[j-1];
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }

    return pi;
}

void solve(const string& s) {

    int n = s.length();

    vector<vector<int>> dp(n, vector<int>(n, INF));

    for(int i = 0; i < n; i++) dp[i][i] = 1;

    for(int i = n-1; i >= 0; i--) {
        for(int j = i+1; j < n; j++) {

            dp[i][j] = (j-i+1);

            for(int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]);
            }

            vector<int> pi = pfun(s.substr(i, j-i+1));
            int p = (j-i+1)-pi[(j-i+1)-1];

            dp[i][j] = min(dp[i][j], dp[i][i+p-1]+(j-i+1)%p);

        }
    }

    cout << dp[0][n-1] << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(true) {
        string s; cin >> s;
        if(s == "*") break;
        solve(s);
    }

    return 0;

}