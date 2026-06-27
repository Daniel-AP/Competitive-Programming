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

void solve() {

    string s, t; cin >> s >> t;
    string ts = t+"#"+s;

    int n = s.length(), m = t.length();

    vector<int> pi = pfun(ts);  
    vector<int> px(n+1), pxx(n+1), dp(n+1);

    for(int i = m+1; i <= n+m; i++) {
        int si = i-m;
        if(pi[i] == m) dp[si] = (pxx[si-m]+(si-m+1))%MOD;
        else dp[si] = dp[si-1];
        px[si] = (px[si-1]+dp[si])%MOD;
        pxx[si] = (pxx[si-1]+px[si])%MOD;
    }

    cout << px[n] << '\n';

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}