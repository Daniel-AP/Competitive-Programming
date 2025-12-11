#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> p(n);
    for(int i = 0; i < n; i++) cin >> p[i];

    int start = 0, end = 1;
    bool b = p[0] > p[1];

    vector<int> ans = {p[0]};
    
    while(true) {
        while(end+1 < n && (p[end] > p[end+1]) == b) end++;
        ans.push_back(p[end]);
        start = end;
        end = start+1;
        if(end >= n) break;
        b = p[start] > p[end];
    }

    cout << ans.size() << '\n';
    for(int x: ans) cout << x << ' ';
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