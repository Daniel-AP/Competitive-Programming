#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
#define MOD 998244353

int binpow(int a, int b) {

    int ans = 1;

    while(b) {
        if(b%2) ans = (ans*a)%MOD;
        a = (a*a)%MOD;
        b /= 2;
    }

    return ans;

}

int inv(int n) {
    return binpow(n, MOD-2);
}

void solve() {

    int n, m; cin >> n >> m;

    map<int, vector<array<int, 3>>> start;
    int notExist = 1;
    
    for(int i = 0; i < n; i++) {
        int l, r, p, q; cin >> l >> r >> p >> q;
        l--, r--;
        start[l].push_back({ r, p, q });
        notExist = notExist*(q-p)%MOD*inv(q)%MOD;
    }
    

    vector<int> dp(m+1);
    dp[m] = 1;

    for(int i = m-1; i >= 0; i--) {
        for(auto [r, p, q]: start[i]) {
            dp[i] += p*inv(q-p)%MOD*dp[r+1]%MOD;
            dp[i] %= MOD;
        }

    }

    cout << notExist*dp[0]%MOD << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}