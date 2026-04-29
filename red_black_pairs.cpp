#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;
    string s1, s2; cin >> s1 >> s2;

    vector<int> dp(n+1);

    for(int i = 1; i <= n; i++) {
        dp[i] = dp[i-1]+(s1[i-1]!=s2[i-1]);
        if(i > 1) {
            dp[i] = min(dp[i], dp[i-2]+(s1[i-1]!=s1[i-2])+(s2[i-1]!=s2[i-2]));
        }
    }

    cout << dp[n] << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}