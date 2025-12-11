#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, x; cin >> n >> x;

    vector<int> c(n);
    for(int i = 0; i < n; i++) cin >> c[i];

    vector<int> dist(x+1, INF);
    dist[0] = 0;

    for(int i = 0; i <= x; i++) {
        if(dist[i] == INF) continue;
        for(int j = 0; j < n; j++) {
            if(i+c[j] > x) continue;
            dist[i+c[j]] = min(dist[i+c[j]], dist[i]+1);
        }
    }

    cout << (dist[x] == INF ? -1 : dist[x]) << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}