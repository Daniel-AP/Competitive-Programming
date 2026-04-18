#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    map<int, int> cnt;

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        cnt[x]++;
    }

    int mex = 0;
    while(cnt[mex]) mex++;

    if(mex == 0) return void(cout << 0 << '\n');

    vector<int> dp(mex);

    for(int i = 0; i < mex; i++) dp[i] = mex*(cnt[i]-1)+i;

    for(int i = mex-1; i >= 0; i--) {
        for(int j = i+1; j < mex; j++) {
            dp[i] = min(dp[i], dp[j]+j*(cnt[i]-1)+i);
        }
    }

    cout << dp[0] << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}