#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int l, r; cin >> l >> r;
    int n = r+1;

    vector<int> ans(n);
    iota(ans.begin(), ans.end(), 0);

    int prev = 0;

    for(int i = 31; i >= 0; i--) {
        if(!(n&(1LL<<i))) continue;
        reverse(ans.begin()+prev, ans.begin()+prev+(1LL<<i));
        prev += (1LL<<i);
    }

    int val = 0;
    for(int i = 0; i < n; i++) val += (i|ans[i]);

    cout << val << '\n';
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