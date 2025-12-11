#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<vector<int>> abc(3, vector<int>(n));

    for(int i = 0; i < n; i++) cin >> abc[0][i];
    for(int i = 0; i < n; i++) cin >> abc[1][i];
    for(int i = 0; i < n; i++) cin >> abc[2][i];
    
    vector<int> p = { 0, 1, 2 };
    vector<pair<int, int>> ans(3);

    bool good = false;

    int tot = 0;
    for(int i = 0; i < n; i++) tot += abc[0][i];

    do {
        int l = 0, r = n-1, sl = abc[p[0]][0], sr = abc[p[2]][n-1], sm = 0;
        while(sl < (tot+2)/3 && l+1 < n) l++, sl += abc[p[0]][l];
        while(sr < (tot+2)/3 && r-1 >= 0) r--, sr += abc[p[2]][r];
        for(int i = l+1; i < r; i++) sm += abc[p[1]][i];
        if(sm >= (tot+2)/3) {
            ans[p[0]] = { 1, l+1 };
            ans[p[1]] = { l+2, r };
            ans[p[2]] = { r+1, n };
            good = true;
            break;
        }
    } while(next_permutation(p.begin(), p.end()));
    
    if(!good) return void(cout << -1 << '\n');
    
    for(int i = 0; i < 3; i++) cout << ans[i].first << ' ' << ans[i].second << ' ';
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