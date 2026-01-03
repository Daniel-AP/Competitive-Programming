#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

const int N = 200005;

int dp[N];

void pre() {

    dp[0] = 0;

    for(int i = 1; i < N; i++) {
        int j = i;
        dp[i] = dp[i-1];
        while(j) dp[i] += j%10, j /= 10;
    }

}

void solve() {

    int n; cin >> n;

    cout << dp[n] << '\n';
    
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