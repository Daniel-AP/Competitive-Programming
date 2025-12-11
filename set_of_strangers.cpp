#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int n, m; cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));
    unordered_set<int> is, extra;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mat[i][j];
            is.insert(mat[i][j]);
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {

            int dirI[] = { -1, 0, 0, 1 };
            int dirJ[] = { 0, -1, 1, 0 };

            for(int k = 0; k < 4; k++) {
                
                int nxI = i+dirI[k];
                int nxJ = j+dirJ[k];

                if(nxI < 0 || nxI >= n || nxJ < 0 || nxJ >= m) continue;
                
                if(mat[i][j] == mat[nxI][nxJ]) extra.insert(mat[nxI][nxJ]);
                
            }

        }
    }

    if(extra.size() == 0) {
        cout << is.size()-1 << endl;
    } else {
        cout << is.size()+extra.size()-2 << endl;
    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}