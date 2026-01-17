#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> s(n+1);
    for(int i = 1; i <= n; i++) cin >> s[i];

    vector<int> dp(n+1, 1);

    for(int i = 2; i <= n; i++) {
        for(int j = 1; j*j <= i; j++) {
            if(i%j != 0) continue;
            if(s[j] < s[i]) dp[i] = max(dp[i], dp[j]+1);
            if(i/j != i && s[i/j] < s[i]) dp[i] = max(dp[i], dp[i/j]+1);
        }
    }

    cout << *max_element(all(dp)) << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}