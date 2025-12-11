#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int n, m; cin >> n >> m;

    vector<string> mat(n);
    for(int i = 0; i < n; i++) cin >> mat[i];

    vector<vector<bool>> row(n, vector<bool>(m, true)), col(n, vector<bool>(m, true));

    for(int i = 0; i < n; i++) {
        bool zero = false, good = true;
        for(int j = 0; j < m; j++) {
            if(!good) row[i][j] = false;
            if(zero && mat[i][j] == '1') {
                row[i][j] = false;
                good = false;
            }
            if(mat[i][j] == '0') zero = true;
        }
    }

    for(int i = 0; i < m; i++) {
        bool zero = false, good = true;
        for(int j = 0; j < n; j++) {
            if(!good) col[j][i] = false;
            if(zero && mat[j][i] == '1') {
                col[j][i] = false;
                good = false;
            }
            if(mat[j][i] == '0') zero = true;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!row[i][j] && !col[i][j] && mat[i][j] == '1') {
                cout << "NO" << endl;
                return;
            }
        }
    }

    cout << "YES" << endl;

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}