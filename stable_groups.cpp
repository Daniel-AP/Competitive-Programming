#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k, x; cin >> n >> k >> x;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());
    
    vector<int> d;

    for(int i = 0; i+1 < n; i++) {
        if(a[i+1]-a[i] > x) {
            d.push_back(a[i+1]-a[i]-1);
        }
    }

    sort(d.begin(), d.end());

    int ans = d.size()+1;

    for(int i = 0; i < d.size(); i++) {
        if(k >= d[i]/x) k -= d[i]/x, ans--;
        else break;
    }

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}