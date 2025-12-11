#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

#define MOD 1000000007
// #define MOD 998244353

const int N = 1e6+5;

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
    return binpow(n, MOD-2);
}

void pre() {

    factorial[0] = 1;

    for(int i = 1; i < N; i++) {
        factorial[i] = (factorial[i-1]*i)%MOD;
    }

}

void solve() {

    string s; cin >> s;
    int n = s.length();

    vector<int> cnt(26);
    for(int i = 0; i < n; i++) cnt[s[i]-'a']++;

    int ans = factorial[n];

    for(int i = 0; i < 26; i++) {
        ans = (ans*inv(factorial[cnt[i]]))%MOD;
    }

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    pre();

    int t = 1;

    while(t--) solve();

    return 0;

}