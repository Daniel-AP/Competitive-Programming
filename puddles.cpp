#include <bits/stdc++.h>
using namespace std;

#define int int
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

int di[] = {-1, 0, 1, 0};
int dj[] = {0, 1, 0, -1};

void solve() {

    int h, w; cin >> h >> w;

    vector<string> g(h);
    for(int i = 0; i < h; i++) cin >> g[i];

    vector<vector<bool>> vis(h, vector<bool>(w));
    
    queue<pair<int, int>> q;
    int ans = 0;

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(vis[i][j] || g[i][j] != '.') continue;
            bool good = true;
            q.push({ i, j });
            vis[i][j] = 1;
            while(!q.empty()) {
                auto [ii, jj] = q.front(); q.pop();
                if(ii == 0 || ii == h-1 || jj == 0 || jj == w-1) good = false;
                for(int k = 0; k < 4; k++) {
                    int nxI = ii+di[k], nxJ = jj+dj[k];
                    if(!(nxI >= 0 && nxI < h && nxJ >= 0 && nxJ < w)) continue;
                    if(vis[nxI][nxJ] || g[nxI][nxJ] != '.') continue;
                    vis[nxI][nxJ] = 1;
                    q.push({ nxI, nxJ }); 
                }
            }
            ans += good;
        }
    }

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}