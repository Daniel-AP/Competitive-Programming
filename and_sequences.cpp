#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

#define MOD 1000000007
// #define MOD 998244353

int factorial[200005];

void pre() {

    factorial[0] = 1;

    for(int i = 1; i <= 200000; i++) factorial[i] = factorial[i-1]*i%MOD;
    
}

void solve() {

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    map<int, int> cnt;
    for(int i = 0; i < n; i++) cnt[a[i]]++;

    int q = a[0];
    for(int i = 1; i < n; i++) q &= a[i];

    cout << cnt[q]*factorial[n-2]%MOD*(cnt[q]-1)%MOD << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    pre();

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}