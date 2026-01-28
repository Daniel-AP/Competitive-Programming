#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

#define MOD 10

int binpow(int a, int b) {

    a %= MOD;

    int ans = 1;

    while(b > 0) {
        if(b&1) ans = ans*a%MOD;
        a = a*a%MOD;
        b >>= 1;
    }

    return ans;

}

void solve() {

    int a, b; cin >> a >> b;

    cout << binpow(a, b) << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}