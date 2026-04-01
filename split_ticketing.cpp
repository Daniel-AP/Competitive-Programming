#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<vector<int>> c(n+1, vector<int>(n+1, -1));

    for(int i = 1; i <= n; i++) {
        for(int j = i+1; j <= n; j++) {
            cin >> c[i][j];
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = i+2; j <= n; j++) {
            for(int k = i+1; k < j; k++) {
                if(c[i][k]+c[k][j] < c[i][j]) return void(cout << "Yes" << '\n');
            }
        }
    }

    cout << "No" << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}