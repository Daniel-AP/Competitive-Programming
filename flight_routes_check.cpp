#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

int n, m, id = 0, cnt = 0;
unordered_map<int, vector<int>> g;

vector<int> ids, low, heads;
vector<bool> on;
stack<int> s;

void dfs(int at) {

    s.push(at);
    on[at] = true;
    ids[at] = low[at] = id++;

    for(int to: g[at]) {
        if(ids[to] == -1) dfs(to);
        if(on[to]) low[at] = min(low[at], low[to]);
    }

    if(ids[at] == low[at]) {
        while(1) {
            int n = s.top(); s.pop();
            on[n] = false;
            low[n] = ids[at];
            if(n == at) break;
        }
        cnt++;
        heads.push_back(at);
    }

}

void solve() {

    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
    }

    ids.assign(n+1, -1);
    low.assign(n+1, 0);
    on.assign(n+1, 0);

    stack<int> s;

    for(int i = 1; i <= n; i++) {
        if(ids[i] == -1) {
            dfs(i);
        }
    }

    if(cnt == 1) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
        cout << heads[0] << " " << heads[1];
    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; t = 1;

    while(t--) solve();

    return 0;

}