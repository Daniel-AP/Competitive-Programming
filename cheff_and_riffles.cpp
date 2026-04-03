#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

vector<int> mult(vector<int>& a, vector<int>& p, int n) {

    vector<int> ans(n+1);

    for(int i = 1; i <= n; i++) {
        ans[i] = a[p[i]];
    }

    return ans;

}

vector<int> binpow(int n, int k) {

    vector<int> ans(n+1), a(n+1);

    iota(all(ans), 0);
    for(int i = 1, j = 1; i <= n/2; i++, j += 2) a[i] = j;
    for(int i = n/2+1, j = 2; i <= n; i++, j += 2) a[i] = j;
    
    while(k) {
        if(k%2) ans = mult(ans, a, n);
        a = mult(a, a, n);
        k /= 2;
    }

    return ans;

}

void solve() {

    int n, k; cin >> n >> k;

    vector<int> ans = binpow(n, k);

    for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
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