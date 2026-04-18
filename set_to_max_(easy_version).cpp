#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n+1), b(n+1);

    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];

    vector<vector<bool>> l(n+2, vector<bool>(n+1)), r(n+2, vector<bool>(n+1));

    for(int i = 1; i <= n; i++) {
        if(a[i] > b[i]) return void(cout << "NO" << '\n');
    }

    for(int i = 1; i <= n; i++) {
        l[i] = l[i-1];
        for(int j = 1; j <= n; j++) {
            if(!l[i][j]) continue;
            if(j < a[i] || j > b[i]) l[i][j] = 0;
        }
        l[i][a[i]] = 1;
    }

    for(int i = n; i >= 1; i--) {
        r[i] = r[i+1];
        for(int j = 1; j <= n; j++) {
            if(!r[i][j]) continue;
            if(j < a[i] || j > b[i]) r[i][j] = 0;
        }
        r[i][a[i]] = 1;
    }

    for(int i = 1; i <= n; i++) {
        if(!l[i][b[i]] && !r[i][b[i]]) return void(cout << "NO" << '\n');
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