#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

#define MOD 1000000007

vector<vector<int>> ans;
vector<vector<bool>> visited;

int dfs(int i, int j, vector<string>& m) {

    int n = m.size();

    if(i == n-1 && j == n-1 && m[i][j] != '*') {
        ans[i][j] = 1;
        visited[i][j] = 1;
        return ans[i][j];
    }

    if(visited[i][j]) return ans[i][j];

    if(i+1 < n && m[i+1][j] != '*') ans[i][j] = (dfs(i+1, j, m)+ans[i][j])%MOD;
    if(j+1 < n && m[i][j+1] != '*') ans[i][j] = (dfs(i, j+1, m)+ans[i][j])%MOD;

    visited[i][j] = 1;

    return ans[i][j];

}

void solve() {

    int n; cin >> n;

    vector<string> m(n);
    for(int i = 0; i < n; i++) cin >> m[i];

    ans.assign(n, vector<int>(n));
    visited.assign(n, vector<bool>(n));

    if(m[0][0] == '*') return void(cout << 0 << '\n');

    dfs(0, 0, m);

    cout << ans[0][0] << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; t = 1;

    while(t--) solve();

    return 0;

}