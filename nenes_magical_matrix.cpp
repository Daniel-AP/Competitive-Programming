#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<pair<int, int>> ops;
    vector<vector<int>> mat(n, vector<int>(n));

    for(int i = n-1; i >= 0; i--) {
        ops.push_back({ 1, i });
        ops.push_back({ 2, i });
    }

    for(auto [op, rc]: ops) {
        if(op == 1) {
            for(int j = 0; j < n; j++) mat[rc][j] = j+1;
        } else {
            for(int j = 0; j < n; j++) mat[j][rc] = j+1;
        }
    }

    int s = 0;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) s += mat[i][j];

    cout << s << ' ' << ops.size() << '\n';

    for(auto [op, rc]: ops) {
        cout << op << ' ' << rc+1 << ' ';
        for(int j = 1; j <= n; j++) cout << j << ' ';
        cout << '\n';
    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}