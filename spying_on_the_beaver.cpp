#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> p(n);
    vector<vector<int>> adj(n);

    p[0] = -1;

    for(int i = 1; i < n; i++) {
        int pa; cin >> pa;
        pa--;
        p[i] = pa;
        adj[i].push_back(pa);
        adj[pa].push_back(i);
    }

    vector<int> can(n);

    int m; cin >> m;
    for(int i = 0; i < m; i++) {
        int x; cin >> x;
        x--;
        can[x] = 1;
    }

    int exc = -1;

    queue<int> q;
    q.push(0);

    while(!q.empty()) {
        int x = q.front(); q.pop();
        if(can[x]) {
            exc = x;
            break;
        }
        for(int y: adj[x]) {
            if(y == p[x]) continue;
            q.push(y);
        }
    }

    cout << m-1 << ' ';
    
    for(int i = 0; i < n; i++) {
        if(!can[i]) continue;
        if(i == exc) continue;
        cout << i+1 << ' ';
    }

    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}