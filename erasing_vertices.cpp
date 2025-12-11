#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

// #define MOD 1000000007
// #define MOD 998244353

int n;
vector<bool> visited;

int dfs(int node, vector<string>& mat) {

    int ans = 1;
    visited[node] = 1;

    for(int i = 0; i < n; i++) {
        if(mat[node][i] == '1' && !visited[i]) {
            ans += dfs(i, mat);
        }
    }

    return ans;

}

void solve() {

    cin >> n;

    vector<string> mat(n);
    for(int i = 0; i < n; i++) cin >> mat[i];

    vector<int> cnt(n);

    for(int i = 0; i < n; i++) {
        visited.assign(n, 0);
        cnt[i] = dfs(i, mat);
    }

    
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}