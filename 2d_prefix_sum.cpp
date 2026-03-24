#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, m; cin >> n >> m;

    vector<vector<int>> mat(n+1, vector<int>(m+1));
    vector<vector<int>> px(n+1, vector<int>(m+1));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> mat[i][j];
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            px[i][j] = mat[i][j]+px[i-1][j]+px[i][j-1]-px[i-1][j-1];
        }
    }

    int uli, ulj, lri, lrj; // upper left i, upper left j, lower right i, lower right j
    cin >> uli >> ulj >> lri >> lrj;

    cout << px[lri][lrj]-px[lri][ulj-1]-px[uli-1][lrj]+px[uli-1][ulj-1] << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}