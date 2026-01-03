#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k; cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) {
        if(a[i]%k == 0) {
            a[i] = k;
        } else {
            a[i] %= k;
        }
    }

    vector<int> ind(n);
    iota(ind.begin(), ind.end(), 0);
    sort(ind.begin(), ind.end(), [&](int i, int j) {
        if(a[i] != a[j]) return a[i] > a[j];
        return i < j;
    });

    for(int i: ind) cout << i+1 << ' ';
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