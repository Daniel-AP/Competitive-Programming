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
            if (i > 0 && 'A' + c != s[i])
                aut[i][c] = aut[pi[i-1]][c];
            else
                aut[i][c] = i + ('A' + c == s[i]);
        }
    }

    return aut;

}

void solve() {

    string s1, s2, virus; cin >> s1 >> s2 >> virus;

    int n = s1.length(), m = s2.length(), v = virus.length();
    s1 = " "+s1, s2 = " "+s2;

    vector<vector<int>> aut = pfunautomaton(virus);
    vector<vector<vector<array<int, 4>>>> dp(n+1, vector<vector<array<int, 4>>>(m+1, vector<array<int, 4>>(v, { -INF, -INF, -INF, 0 })));

    for(int j = 0; j <= m; j++) dp[0][j][0] = { 0, -1, -1, 0 };
    for(int i = 0; i <= n; i++) dp[i][0][0] = { 0, -1, -1, 0 };

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            for(int k = 0; k < v; k++) {

                if(i+1 <= n && j+1 <= m) dp[i+1][j+1][k] = max(dp[i+1][j+1][k], dp[i][j][k]);
                if(i+1 <= n) dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]);
                if(j+1 <= m) dp[i][j+1][k] = max(dp[i][j+1][k], dp[i][j][k]);

                if(i+1 <= n && j+1 <= m && s1[i+1] == s2[j+1]) {
                    int ns = aut[k][s1[i+1]-'A'];
                    if(ns < v) dp[i+1][j+1][ns] = max(dp[i+1][j+1][ns], { dp[i][j][k][0]+1, i+1, j+1, k });
                }

            }
        }
    }

    int best = 0, k = -1;

    for(int kk = 0; kk < v; kk++) {
        if(dp[n][m][kk][0] > best) {
            best = dp[n][m][kk][0];
            k = kk;
        }
    }

    if(k == -1) return void(cout << 0 << '\n');

    string ans;
    int i = dp[n][m][k][1], j = dp[n][m][k][2], nxk = dp[n][m][k][3];

    while(i > 0 && j > 0) {
        ans += s1[i];
        int nxi = dp[i-1][j-1][nxk][1], nxj = dp[i-1][j-1][nxk][2];
        nxk = dp[i-1][j-1][nxk][3];
        i = nxi, j = nxj;
    }

    reverse(all(ans));

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}