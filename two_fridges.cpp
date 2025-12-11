#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<pair<int, int>> a(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    for(int i = -100; i <= 100; i++) {
        for(int j = -100; j <= 100; j++) {
            bool bad = false;
            for(int k = 0; k < n; k++) {
                if((i < a[k].first || i > a[k].second) && (j < a[k].first || j > a[k].second)) {
                    bad = true;
                    break;
                }
            }
            if(bad) continue;
            return void(cout << i << ' ' << j << '\n');
        }
    }

    cout << -1 << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}