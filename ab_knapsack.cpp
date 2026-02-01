#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, m, s, A, B; cin >> n >> m >> s >> A >> B;

    vector<int> a(n), b(m);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());

    int pxa = 0, ans = 0;

    vector<int> pxb(m+1);
    partial_sum(all(b), pxb.begin()+1);

    for(int i = 0; i <= n && i*A <= s; i++) {
        ans = max(ans, pxa+pxb[min((s-i*A)/B, m)]);
        pxa += a[i];
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