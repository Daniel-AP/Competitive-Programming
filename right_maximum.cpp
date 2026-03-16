#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<pair<int, int>> a(n);
    
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        a[i] = {x, i};
    }

    sort(all(a));

    int ans = 0, cnt = 0;

    for(int i = 0; i < n; i++) {
        if(a[i].second == 0) {
            ans = i;
            break;
        }
    }

    int mn = INF;

    for(int i = n-1; i > ans; i--) {
        if(a[i].second >= mn) cnt++;
        mn = min(mn, a[i].second);
    }

    cout << n-ans-cnt << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}