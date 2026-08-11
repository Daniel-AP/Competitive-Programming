#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
#define MOD 998244353

const int N = 5*1e6;

int factorial[N];

int binpow(int a, int b) {

    a %= MOD;

    int ans = 1;

    while(b) {
        if(b&1) ans = (ans*a)%MOD;
        a = (a*a)%MOD;
        b >>= 1;
    }

    return ans;

}

int inv(int n) {

    n %= MOD;

    return binpow(n, MOD-2);

}

int comb(int n, int k) {

    if(k < 0 || k > n) return 0;

    return factorial[n]*inv(factorial[k])%MOD*inv(factorial[n-k])%MOD;

}

void pre() {

    factorial[0] = 1;
    for(int i = 1; i < N; i++) factorial[i] = (factorial[i-1]*i)%MOD;

}

void solve() {

    int n; cin >> n;
    string s; cin >> s;

    int cnt0 = 0, cnt1 = 0;

    for(int i = 0; i < n; i++) {
        cnt0 += (s[i] == '0');
        cnt1 += (s[i] == '1');
    }

    if(cnt0 == n || cnt1 == n) return void(cout << 1 << '\n');

    int seg0 = 0, seg1 = 0;
    int cur = 1;

    for(int i = 1; i < n; i++) {
        if(s[i] == s[i-1]) cur++;
        else if(s[i-1] == '0') {
            seg0++;
            cur = 1;
        } else {
            seg1++;
            cur = 1;
        }
    }

    if(s.back() == '0') seg0++;
    if(s.back() == '1') seg1++;

    cout << comb(cnt0-1, seg0-1)*comb(cnt1-1, seg1-1)%MOD << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    pre();

    while(t--) solve();

    return 0;

}