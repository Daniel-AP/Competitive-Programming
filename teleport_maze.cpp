#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

int dy[] = { 0, -1, 0, 1 };
int dx[] = { -1, 0, 1, 0 };

void solve() {

    int h, w; cin >> h >> w;

    vector<vector<char>> s(h, vector<char>(w));
    vector<vector<int>> d(h, vector<int>(w, INF));
    vector<vector<pair<int, int>>> abcs(26, vector<pair<int, int>>());
    vector<bool> used(26);

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin >> s[i][j];
        }
    }

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(s[i][j] == '.' || s[i][j] == '#') continue;
            abcs[s[i][j]-'a'].push_back({ i, j });
        }
    }

    queue<array<int, 3>> q;
    d[0][0] = 0;
    q.push({ 0, 0, 0 });
    
    while(!q.empty()) {

        auto [i, j, c] = q.front(); q.pop();

        if(c != d[i][j]) continue;

        for(int k = 0; k < 4; k++) {
            int nxI = i+dy[k], nxJ = j+dx[k];
            if(!(nxI >= 0 && nxI < h && nxJ >= 0 && nxJ < w)) continue;
            if(s[nxI][nxJ] == '#') continue;
            if(d[nxI][nxJ] > c+1) {
                d[nxI][nxJ] = c+1;
                q.push({ nxI, nxJ, c+1 });
            }
        }

        if(s[i][j] != '.' && s[i][j] != '#' && !used[s[i][j]-'a']) {
            used[s[i][j]-'a'] = 1;
            for(auto [ii, jj]: abcs[s[i][j]-'a']) {
                if(d[ii][jj] > c+1) {
                    d[ii][jj] = c+1;
                    q.push({ ii, jj, c+1 });
                }
            }
        }
        
    }

    cout << ((d[h-1][w-1] == INF) ? -1 : d[h-1][w-1]) << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}