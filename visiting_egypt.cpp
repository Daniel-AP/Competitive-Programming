#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

#define MOD 1000000007
// #define MOD 998244353

void solve() {

    int t; cin >> t;
    int mx = 0;

    vector<array<int, 3>> tt(t);

    for(int i = 0; i < t; i++) {
        cin >> tt[i][0] >> tt[i][1] >> tt[i][2];
        mx = max(mx, tt[i][0]);
    }

    mx = 212*mx;

    vector<int> dp(mx+1);
    dp[0] = 1;

    int coins[] = { 1, 2, 4, 20, 40, 80, 200, 400, 800 };

    for(int i = 1; i <= mx; i++) {
        for(int c: coins) {
            if(i < c) continue;
            dp[i] += dp[i-c];
            dp[i] %= MOD;
        }
    }

    for(int i = 0; i < t; i++) {

        int ans = dp[212*tt[i][0]];
        int d1 = abs(tt[i][1]-ans);
        int d2 = abs(tt[i][2]-ans);

        if(d1 == 0 && d2 == 0) cout << "TIE" << '\n';
        else if(d1 == d2) cout << "NONE" << '\n';
        else if(d1 < d2) cout << "Mikel" << '\n';
        else cout << "Andrew" << '\n';

    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}