#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int k, n; cin >> k >> n;

    vector<int> ans = {1};
    int d = 1;

    for(int i = 0; i < k-1; i++) {
        int has = n-(ans.back()+d);
        if(ans.size()+has+1 >= k) ans.push_back(ans.back()+d);
        else ans.push_back(ans.back()+1);
        d++;
    }

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