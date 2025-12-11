#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

vector<string> rotate(vector<string>& mat) {

    int n = mat.size();

    vector<string> ans(n, string(n, ' '));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ans[j][i] = mat[i][j];
        }
    }

    for(int i = 0; i < n; i++) reverse(ans[i].begin(), ans[i].end());

    return ans;

}

void solve() {

    int n; cin >> n;

    vector<string> a(n, string(n, ' '));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    vector<string> rot90 = rotate(a);
    vector<string> rot180 = rotate(rot90);
    vector<string> rot270 = rotate(rot180);

    vector<vector<int>> cnt0(n, vector<int>(n));
    vector<vector<int>> cnt1(n, vector<int>(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cnt0[i][j] += a[i][j] == '0';
            cnt1[i][j] += a[i][j] == '1';
            cnt0[i][j] += rot90[i][j] == '0';
            cnt1[i][j] += rot90[i][j] == '1';
            cnt0[i][j] += rot180[i][j] == '0';
            cnt1[i][j] += rot180[i][j] == '1';
            cnt0[i][j] += rot270[i][j] == '0';
            cnt1[i][j] += rot270[i][j] == '1';
        }
    }

    int ans = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ans += min(cnt0[i][j], cnt1[i][j]);
        }
    }

    cout << ans/4 << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}