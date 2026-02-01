#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    
    int cur = 0;
    for(int i = 1; i <= n; i++) cur ^= a[i];

    if(cur == 0) return void(cout << "YES" << '\n');

    vector<int> px(n+1);
    for(int i = 1; i <= n; i++) px[i] = (px[i-1]^a[i]);

    for(int l = 1; l+2 <= n; l++) {
        for(int r = l+1; r < n; r++) {
            int ll = px[l], mm = px[r]^px[l], rr = px[n]^px[r];
            if(ll == mm && mm == rr) return void(cout << "YES" << '\n');
        }
    }

    cout << "NO" << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}