#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

#define MOD 1000000007
// #define MOD 998244353

int binpow(int a, int b) {

    a %= MOD;

    int ans = 1;

    while(b) {
        if(b%2) ans = (ans*a)%MOD;
        a = (a*a)%MOD;
        b /= 2;
    }

    return ans;

}

void solve() {

    int n, x; cin >> n >> x;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    map<int, int> mp;
    for(int i = 0; i < n; i++) mp[a[n-1]-a[i]]++;

    int s = 0;
    for(int i = 0; i < n; i++) s += a[i];

    int ans = binpow(x, s-a[n-1]);
    int cur = 0, p = 0;

    while((cur+mp[p])%x == 0 && p < a[n-1]) {
        ans *= x;
        ans %= MOD;
        cur += mp[p];
        cur /= x;
        p++;
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