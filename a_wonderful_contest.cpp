#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> cnt(100);
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        cnt[100/x] += 100/(100/x);
    }

    vector<int> dp(100, -1);
    dp[0] = 0;

    for(int i = 1; i < 100; i++) {
        int c = min(cnt[i], 100/i);
        for(int j = 0; j < 100; j++) {
            if(dp[j] >= 0) dp[j] = c;
            else if(j >= i && dp[j-i] > 0) dp[j] = dp[j-i]-1;
            else dp[j] = -1;
        }
    }

    for(int i = 1; i < 100; i++) {
        if(dp[i] == -1) return void(cout << "NO" << '\n');
    }

    cout << "YES" << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}