#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<bool> has(n+1);

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        has[x] = 1;
    }

    vector<vector<int>> divs(n+1);

    for(int i = 1; i <= n; i++) {
        if(!has[i]) continue;
        for(int j = i; j <= n; j += i) {
            divs[j].push_back(i);
        }
    }

    vector<int> dp(n+1, INF);
    
    for(int i = 1; i <= n; i++) {
        if(has[i]) dp[i] = 1;
    }

    for(int i = 1; i <= n; i++) {
        for(int j: divs[i]) {
            if(j == 1) continue;
            dp[i] = min(dp[i], dp[i/j]+1);
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << (dp[i] == INF ? -1 : dp[i]) << ' ';
    }

    cout << '\n';

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}