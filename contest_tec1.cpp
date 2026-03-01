#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<vector<int>> adj(n+1);

    for(int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    string s; cin >> s;

    int cntq = 0, cnt0 = 0, cnt1 = 0, cnt = 0;

    for(int i = 2; i <= n; i++) {
        cnt += (s[i-1]=='?');
        if(adj[i].size() != 1) continue;
        if(s[i-1] == '?') cntq++; 
        if(s[i-1] == '0') cnt0++;
        if(s[i-1] == '1') cnt1++;
    }

    cnt -= cntq;

    if(s[0] == '?') {
        int ans = max(cnt0, cnt1)+cntq/2;
        if(cnt%2) ans = max(ans, min(cnt0, cnt1)+(cntq+1)/2);
        if(cntq) ans = max({ ans, min(cnt0+1, cnt1)+(cntq)/2, min(cnt0, cnt1+1)+(cntq)/2 });
        cout << ans;
    } else if(s[0] == '0') cout << cnt1+(cntq+1)/2;
    else cout << cnt0+(cntq+1)/2;

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