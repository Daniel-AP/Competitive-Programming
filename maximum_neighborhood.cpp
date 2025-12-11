#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

int di[] = { 0, -1, 0, 1 };
int dj[] = { -1, 0, 1, 0 };

void solve() {

    int n; cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));
    int cur = 1;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            mat[i][j] = cur;
            cur++;
        }
    }

    int ans = 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int t = mat[i][j];
            for(int k = 0; k < 4; k++) {
                int nxI = i+di[k], nxJ = j+dj[k];
                if(nxI >= 0 && nxI < n && nxJ >= 0 && nxJ < n) {
                    t += mat[nxI][nxJ];
                }
            }
            ans = max(ans, t);
        }
    }

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}