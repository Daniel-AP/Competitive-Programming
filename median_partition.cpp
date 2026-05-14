#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];

    vector<int> b(a);
    sort(all(b));

    int m = b[n/2+1];

    vector<int> dp(n+1, -INF);
    dp[0] = 0;
    
    for(int i = 1; i <= n; i++) {
        int lt = (a[i]<m), eq = (a[i]==m), gt = (a[i]>m);
        for(int j = i; j > 0; j -= 2) {
            if(dp[j-1] != -INF && lt < (lt+eq+gt+1)/2 && lt+eq >= (lt+eq+gt+1)/2) {
                dp[i] = max(dp[i], 1+dp[j-1]);
            }
            if(j-2 > 0) {
                lt += (a[j-1]<m);
                eq += (a[j-1]==m);
                gt += (a[j-1]>m);
                lt += (a[j-2]<m);
                eq += (a[j-2]==m);
                gt += (a[j-2]>m);
            }
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