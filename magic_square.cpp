#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;
    vector<vector<int>> ans(n, vector<int>(n));

    ans[0][(n-1)/2] = 1;

    int r = 0, c = (n-1)/2, k = 1;

    for(int i = 0; i < n*n-1; i++) {
        if(ans[((r-1)%n+n)%n][(c+1)%n] == 0) {
            ans[((r-1)%n+n)%n][(c+1)%n] = ++k;
            r = ((r-1)%n+n)%n, c = (c+1)%n;
        } else {
            ans[(r+1)%n][c] = ++k;
            r = (r+1)%n;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}