#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

#define MOD 1000000007
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
            if (i > 0 && 'A' + c != s[i])
                aut[i][c] = aut[pi[i-1]][c];
            else
                aut[i][c] = i + ('A' + c == s[i]);
        }
    }

    return aut;

}

int binpow(int a, int b) {

    a %= MOD;

    int ans = 1;

    while(b) {
        if(b&1) ans = (ans*a)%MOD;
        a = (a*a)%MOD;
        b >>= 1;
    }

    return ans;

}

void solve() {

    int n; cin >> n;
    string s; cin >> s;

    int m = s.length();

    vector<vector<int>> aut = pfunautomaton(s);
    vector<vector<array<int, 2>>> dp(n+1, vector<array<int, 2>>(m+1, {0, 0}));

    dp[0][0][0] = 1;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= m; j++) {
            for(char ch = 'A'; ch <= 'Z'; ch++) {
                int ns = aut[j][ch-'A'];
                if(ns == m) dp[i+1][ns][1] += dp[i][j][0]+dp[i][j][1], dp[i+1][ns][1] %= MOD;
                else dp[i+1][ns][1] += dp[i][j][1], dp[i+1][ns][0] += dp[i][j][0], dp[i+1][ns][1] %= MOD, dp[i+1][ns][0] %= MOD;
            }
        }
    }

    int ans = 0;
    for(int j = 0; j <= m; j++) ans += dp[n][j][1], ans %= MOD;

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}