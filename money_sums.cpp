#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

const int N = 1000000;

void solve() {

    int n; cin >> n;

    vector<int> x(n);
    for(int i = 0; i < n; i++) cin >> x[i];

    vector<bool> dp(N+1);
    dp[0] = 1;

    for(int i = 0; i < n; i++) {
        for(int j = N; j >= x[i]; j--) {
            if(dp[j-x[i]]) dp[j] = 1;
        }
    }

    cout << count(dp.begin()+1, dp.end(), 1) << '\n';

    for(int i = 1; i <= N+1; i++) {
        if(dp[i]) cout << i << ' ';
    }

    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}