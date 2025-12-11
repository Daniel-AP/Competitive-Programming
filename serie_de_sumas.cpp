#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

#define MOD 10000000

int binpow(int a, int b) {

    a %= MOD;
    int res = 1;

    while(b > 0) {
        if(b & 1) res = res*a%MOD;
        a = a*a%MOD;
        b >>= 1;
    }

    return res;

}

void solve() {

    int n; cin >> n;
    int ans = 0;

    for(int i = 1; i <= n; i++) {
        ans = (ans+binpow(i, i))%MOD;
    }

    string s = to_string(ans);

    cout << s;
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; t = 1;

    while(t--) solve();

    return 0;

}