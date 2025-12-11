#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

int di[] = { 0, -1, 0, 1 };
int dj[] = { -1, 0, 1, 0 };

void solve() {

    int n, m; cin >> n >> m;

    vector<string> maze(n);
    for(int i = 0; i < n; i++) cin >> maze[i];

    vector<vector<bool>> exits(n, vector<bool>(m));
    queue<pair<int, int>> q;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i == 0 && maze[i][j] == 'U') q.push({ i, j });
            else if(i == n-1 && maze[i][j] == 'D') q.push({ i, j });
            else if(j == 0 && maze[i][j] == 'L') q.push({ i, j });
            else if(j == m-1 && maze[i][j] == 'R') q.push({ i, j });
        }
    }

    while(!q.empty()) {

        auto [i, j] = q.front(); q.pop();

        exits[i][j] = 1;

        for(int k = 0; k < 4; k++) {
            int nxI = i+di[k], nxJ = j+dj[k];
            if(!(nxI >= 0 && nxI < n && nxJ >= 0 && nxJ < m && !exits[nxI][nxJ])) continue;
            if(k == 0 && maze[nxI][nxJ] == 'R') q.push({ nxI, nxJ });
            if(k == 1 && maze[nxI][nxJ] == 'D') q.push({ nxI, nxJ });
            if(k == 2 && maze[nxI][nxJ] == 'L') q.push({ nxI, nxJ });
            if(k == 3 && maze[nxI][nxJ] == 'U') q.push({ nxI, nxJ });
        }
        
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            bool all = true;
            for(int k = 0; k < 4; k++) {
                int nxI = i+di[k], nxJ = j+dj[k];
                if(!(nxI >= 0 && nxI < n && nxJ >= 0 && nxJ < m)) continue;
                if(!exits[nxI][nxJ]) all = false;
            }
            if(all) q.push({ i, j });
        }
    }

    while(!q.empty()) {

        auto [i, j] = q.front(); q.pop();

        bool all = true;
        for(int k = 0; k < 4; k++) {
            int nxI = i+di[k], nxJ = j+dj[k];
            if(!(nxI >= 0 && nxI < n && nxJ >= 0 && nxJ < m)) continue;
            if(!exits[nxI][nxJ]) all = false;
        }

        if(all) {
            exits[i][j] = 1;
            for(int k = 0; k < 4; k++) {
                int nxI = i+di[k], nxJ = j+dj[k];
                if(nxI >= 0 && nxI < n && nxJ >= 0 && nxJ < m && !exits[nxI][nxJ]) q.push({ nxI, nxJ });
            }
        }

    }

    int ans = 0;
    for(int i = 0; i < n; i++) ans += count(exits[i].begin(), exits[i].end(), 0);

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}