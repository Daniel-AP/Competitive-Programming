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
    for(int i = 0; i < n; i++) a[i] = abs(a[i]);

    vector<int> ind(n);
    iota(all(ind), 0);
    sort(all(ind), [&](int i, int j) { return a[i] < a[j]; });

    int i = find(all(ind), 0)-ind.begin()+1;
    int cnt = n-i;

    if(i == (n+1)/2) {
        cout << "YES" << '\n';
    } else if(i < (n+1)/2) {
        cout << (cnt >= (n+1)/2-i ? "YES" : "NO") << '\n';
    } else {
        cout << (cnt >= (n+1)/2-1 ? "YES" : "NO") << '\n';
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