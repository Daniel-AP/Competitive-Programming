#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

int binpow(int a, int b, int m) {

    a %= m;

    int ans = 1;

    while(b) {
        if(b%2) ans = (ans*a)%m;
        a = (a*a)%m;
        b /= 2;
    }

    return ans;

}

void solve(int t) {

    int n, k, m; cin >> n >> k >> m;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int ans = 0;

    for(int i = 0; i < n; i++) {
        ans += (a[i]*binpow(n, k-1, m)%m*k)%m;
        ans %= m;
    }

    cout << "Case " << t << ": " << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    for(int i = 1; i <= t; i++) solve(i);

    return 0;

}