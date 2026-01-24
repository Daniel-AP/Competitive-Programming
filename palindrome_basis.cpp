#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

#define MOD 1000000007
// #define MOD 998244353

const int N = 40000;

vector<int> dp(N+1), p;

bool check(int k) {

    int rv = 0, m = k;

    while(k) rv *= 10, rv += k%10, k /= 10;

    return rv == m;

}

void pre() {

    for(int i = 1; i <= N; i++) {
        if(!check(i)) continue;
        p.push_back(i);
    }

    dp[0] = 1;

    for(int x: p) {
        for(int i = 1; i <= N; i++) {
            if(i-x >= 0) dp[i] += dp[i-x];
            dp[i] %= MOD;
        }
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