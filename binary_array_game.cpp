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

    if(count(all(a), 1) == n) return void(cout << "Alice" << '\n');

    int l = 0, r = n-1;

    while(l < n && a[l] == 1) l++;
    while(r >= 0 && a[r] == 1) r--;

    if(r-l+1 == n) cout << "Bob" << '\n';
    else cout << "Alice" << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}