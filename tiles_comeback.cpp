#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k; cin >> n >> k;

    vector<int> c(n);
    for(int i = 0; i < n; i++) cin >> c[i];

    if(c[0] == c[n-1] && count(all(c), c[0]) >= k) return void(cout << "YES" << '\n');

    int cnt1 = 0, cnt2 = 0;

    int l = 0;
    for(; l < n; l++) {
        cnt1 += (c[l]==c[0]);
        if(cnt1 == k) break;
    }

    for(int i = l+1; i < n; i++) {
        cnt2 += (c[i]==c[n-1]);
        if(cnt2 == k) break;
    }

    if(cnt1 == k && cnt2 == k) cout << "YES" << '\n';
    else cout << "NO" << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}