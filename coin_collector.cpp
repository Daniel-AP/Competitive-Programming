#include <bits/stdc++.h>
using namespace std;

#define int long long

int dfs(int start) {

    

}

void solve() {

    int n, m; cin >> n >> m;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    map<int, int> adj_list;

    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj_list[a] = b;
    }



}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}