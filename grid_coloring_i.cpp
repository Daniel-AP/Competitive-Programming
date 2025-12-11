#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int n, m; cin >> n >> m;

    vector<string> grid(n);
    
    for(int i = 0; i < n; i++) cin >> grid[i];

    vector<vector<char>> colored(n, vector<char>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            set<char> cant = { grid[i][j] };
            if(i > 0) cant.insert(colored[i-1][j]);
            if(j > 0) cant.insert(colored[i][j-1]);
            for(int k = 0; k < 4; k++) {
                if(!cant.count((char)('A'+k))) {
                    colored[i][j] = (char)('A'+k);
                    break;
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << colored[i][j];
        }
        cout << endl;
    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}