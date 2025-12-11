#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int n; cin >> n;

    queue<pair<int, int>> q;
    vector<vector<int>> dist(n, vector<int>(n, -1));

    int dirX[] = { -2, -2, -1, 1, 2, 2, -1, 1 };
    int dirY[] = { -1, 1, -2, -2, -1, 1, 2, 2 };

    q.push({ 0, 0 });
    dist[0][0] = 0;
    
    while(!q.empty()) {

        auto [x, y] = q.front();
        q.pop();

        for(int i = 0; i < 8; i++) {

            int nx = x+dirX[i], ny = y+dirY[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(dist[nx][ny] != -1) continue;

            q.push({ nx, ny });
            dist[nx][ny] = dist[x][y]+1;

        }

    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << dist[i][j] << " ";
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