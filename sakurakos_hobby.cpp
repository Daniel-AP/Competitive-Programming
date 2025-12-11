#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    int n; cin >> n;

    vector<int> p(n+1), ans(n+1);
    vector<bool> visited(n+1);
    
    for(int i = 1; i <= n; i++) cin >> p[i];
    string s; cin >> s;

    map<int, int> adj;
    for(int i = 1; i <= n; i++) adj[i] = p[i];

    queue<int> q;
    
    for(int i = 1; i <= n; i++) {

        if(visited[i]) continue;

        q.push(i);

        int cnt = 0;
        vector<int> cc;

        while(!q.empty()) {

            int x = q.front(); q.pop();

            visited[x] = 1;
            cc.push_back(x);
            cnt += (s[x-1]=='0');

            if(!visited[adj[x]]) q.push(adj[x]);

        }

        for(int x: cc) ans[x] = cnt;

    }

    for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}