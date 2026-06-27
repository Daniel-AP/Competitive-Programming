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

vector<vector<int>> pfunautomaton(string s) {

    s += '#';
    int n = s.size();

    vector<vector<int>> aut;
    aut.assign(n, vector<int>(26));

    vector<int> pi = pfun(s);
    for (int i = 0; i < n; i++) {
        for (int c = 0; c < 26; c++) {
            if (i > 0 && 'a' + c != s[i])
                aut[i][c] = aut[pi[i-1]][c];
            else
                aut[i][c] = i + ('a' + c == s[i]);
        }
    }

    return aut;

}

void solve() {

    string s, t; cin >> s >> t;
    vector<vector<int>> aut = pfunautomaton(t);

    int n = s.length(), m = t.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -INF));

    dp[0][0] = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= m; j++) {
            if(s[i] == '?') {
                for(char ch = 'a'; ch <= 'z'; ch++) {
                    int ns = aut[j][ch-'a'];
                    dp[i+1][ns] = max(dp[i+1][ns], dp[i][j]+(ns==m));
                }
            } else {
                int ns = aut[j][s[i]-'a'];
                dp[i+1][ns] = max(dp[i+1][ns], dp[i][j]+(ns==m));
            }
        }
    }

    int ans = 0;
    for(int j = 0; j <= m; j++) ans = max(ans, dp[n][j]);

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}