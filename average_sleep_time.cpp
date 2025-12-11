#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    double n, k; cin >> n >> k;

    vector<double> a(n);
    for(double i = 0; i < n; i++) cin >> a[i];

    double cur = 0;
    long double s = 0;

    for(int i = 0; i < k; i++) cur += a[i];
    for(int i = k-1; i+1 < n; i++) s += cur, cur += a[i+1]-a[i-k+1];
    s += cur;

    cout << fixed << setprecision(9) << s/(long double)(n-k+1) << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}