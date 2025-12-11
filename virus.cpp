#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, m; cin >> n >> m;

    vector<int> a(m);
    for(int i = 0; i < m; i++) cin >> a[i];

    if(m == n) return void(cout << n << '\n');

    sort(a.begin(), a.end());

    vector<int> diff = { n-a[m-1]+a[0]-1 };

    for(int i = 0; i+1 < m; i++) {
        diff.push_back(a[i+1]-a[i]-1);
    }

    sort(diff.rbegin(), diff.rend());

    int ans = n;

    for(int i = 0, j = 0; i < diff.size(); i++, j += 4) {
        diff[i] -= j;
        if(diff[i] == 1) {
            ans--;
        } else if(diff[i] >= 2) {
            ans -= diff[i]-1;
        }
    }

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}