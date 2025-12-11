#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int n, m; cin >> n >> m;
    char c; cin >> c;

    vector<vector<char>> a(n, vector<char>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    set<char> ans;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == '.' || a[i][j] == c) continue;
            vector<pair<int, int>> candidates = { {i-1, j}, {i+1, j}, {i, j-1}, {i, j+1} };
            for(pair<int, int> d: candidates) {
                if(d.first >= 0 && d.first < n && d.second >= 0 && d.second < m) {
                    if(a[d.first][d.second] == c) ans.insert(a[i][j]);
                }
            }
        }
    }

    cout << ans.size() << endl;

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}