#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<array<int, 3>> lr(n);

    for(int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        lr[i] = {l, r, i};
    }

    sort(all(lr));

    int mx = lr[0][1];
    vector<int> ans(n);

    for(int i = 1; i < n; i++) {
        if(mx < lr[i][0]) {
            for(int j = 0; j < i; j++) ans[lr[j][2]] = 1;
            for(int j = i; j < n; j++) ans[lr[j][2]] = 2;
            break;
        }
        mx = max(mx, lr[i][1]);
    }

    if(ans[0] == 0) cout << -1 << '\n';
    else {
        for(int x: ans) cout << x << ' ';
        cout << '\n';
    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}