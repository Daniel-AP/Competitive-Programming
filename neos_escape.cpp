#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;
 
    vector<pair<int, int>> a;
    
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        if(a.empty() || a.back().first != x) a.push_back({ x, a.size() });
    }
 
    sort(a.rbegin(), a.rend());
 
    vector<bool> reach(n);
 
    int ans = 0;
 
    for(auto [val, i]: a) {
        if(!reach[i]) ans++;
        if(i-1 >= 0) reach[i-1] = 1;
        if(i+1 < n) reach[i+1] = 1;
    }
 
    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}