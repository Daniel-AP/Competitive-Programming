#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

int z(int n) {

    int ans = 0, f = 10;
    while(n%f == 0) ans++, f *= 10;

    return ans;

}

void solve() {

    int n, m; cin >> n >> m;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int tot = 0;
    for(int i = 0; i < n; i++) tot += to_string(a[i]).length();

    sort(a.begin(), a.end(), [&](int x, int y) {
        return z(x) > z(y);
    });

    for(int i = 0; i < n && a[i]%10 == 0; i += 2) {
        tot -= z(a[i]);
    }

    if(tot > m) cout << "Sasha" << '\n';
    else cout << "Anna" << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}