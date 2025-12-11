#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

const int N = 200000;

void solve() {

    int n; cin >> n;
    map<int, int> cnt;

    string ans = "NO";
    vector<vector<int>> mat(n, vector<int>());

    for(int i = 0; i < n; i++) {

        int k; cin >> k;

        mat[i].resize(k);

        for(int j = 0; j < k; j++) {
            cin >> mat[i][j];
            cnt[mat[i][j]]++;
        }

    }

    for(int i = 0; i < n; i++) {
        bool good = true;
        for(int x: mat[i]) {
            if(cnt[x] == 1) good = false;
        }
        if(good) ans = "YES";
    }

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}