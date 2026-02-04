#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353



void solve() {

    int n; cin >> n;

    vector<int> x(n);
    for(int i = 0; i < n; i++) cin >> x[i];

    vector<array<int, 2>> dp0(n), dp1(n), dp2(n);

    for(int i = n-1; i >= 0; i--) {
        for(int j = i; j < n; j++) {
            dp0[j][0] = x[i], dp0[j][1] = x[j];
            if(i+1 <= j-1 && i+2 <= j) dp0[j][0] = x[i]+min(max(dp1[j-1][0], dp1[j-1][1]), max(dp2[j][0], dp2[j][1]));
            else if(i+1 <= j-1) dp0[j][0] = x[i]+max(dp1[j-1][0], dp1[j-1][1]);
            else if(i+2 <= j) dp0[j][0] = x[i]+max(dp2[j][0], dp2[j][1]);
            if(i+1 <= j-1 && j-2 >= i) dp0[j][1] = x[j]+min(max(dp1[j-1][0], dp1[j-1][1]), max(dp0[j-2][0], dp0[j-2][1]));
            else if(i+1 <= j-1) dp0[j][1] = x[j]+max(dp1[j-1][0], dp1[j-1][1]);
            else if(j-2 >= i) dp0[j][1] = x[j]+max(dp0[j-2][0], dp0[j-2][1]);
        }
        dp2 = dp1;
        dp1 = dp0;
    }

    cout << max(dp0[n-1][0], dp0[n-1][1]) << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}