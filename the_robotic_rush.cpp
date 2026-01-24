#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, m, k; cin >> n >> m >> k;
 
    vector<pair<int, int>> c;
 
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        c.push_back({ x, i });
    }
 
    for(int i = 0; i < m; i++) {
        int x; cin >> x;
        c.push_back({ x, -1 });
    }
 
    sort(all(c));
 
    int last = -1;
 
    vector<pair<int, int>> rngs(n);
 
    for(int i = 0; i < c.size(); i++) {
        auto [val, j] = c[i];
        if(j == -1) {
            last = val;
        } else {
            if(last != -1) rngs[j].first = last-val;
            else rngs[j].first = -INF;
        }
    }
 
    last = -1;
 
    for(int i = c.size()-1; i >= 0; i--) {
        auto [val, j] = c[i];
        if(j == -1) {
            last = val;
        } else {
            if(last != -1) rngs[j].second = last-val;
            else rngs[j].second = INF;
        }
    }

    map<int, vector<int>> mp;

    for(int i = 0; i < n; i++) {
        mp[rngs[i].first].push_back(i);
        mp[rngs[i].second].push_back(i);
    }

    int cur = 0;

    string ins; cin >> ins;

    set<int> dead;

    for(int i = 0; i < k; i++) {
        if(ins[i] == 'L') cur--;
        else cur++;
        for(int j: mp[cur]) dead.insert(j);
        mp[cur].clear();
        cout << n-dead.size() << ' ';
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