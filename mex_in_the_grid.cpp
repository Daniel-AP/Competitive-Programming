#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

void solve() {

    int n; cin >> n;

    vector<vector<int>> ans(n, vector<int>(n)), visited(n, vector<int>(n));

    int dy = 0, dx = 1, y = 0, x = 0, val = n*n-1;

    for(int i = n*n-1; i >= 0; i--) {

        ans[y][x] = val--;
        visited[y][x] = 1;

        int nxY = y+dy, nxX = x+dx;

        if(nxY < 0 || nxY >= n || nxX < 0 || nxX >= n || visited[nxY][nxX] == 1) {
            int t = dy;
            dy = dx, dx = -t;
            nxY = y+dy, nxX = x+dx;
        }

        y = nxY, x = nxX;

    }    

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
        
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}