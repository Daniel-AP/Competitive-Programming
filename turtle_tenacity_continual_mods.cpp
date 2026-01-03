#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    int cnt = count(a.begin(), a.end(), a[0]);

    if(cnt == 1) return void(cout << "YES" << '\n');

    for(int i = 1; i < n; i++) {
        if(a[i]%a[0] == 0) continue;
        return void(cout << "YES" << '\n');
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