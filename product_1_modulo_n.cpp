#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

#define MOD 1000000007

int binpow(int a, int b, int m) {

    int ans = 1;

    a %= m;

    while(b) {
        if(b&1) {
            ans *= a;
            ans %= m;
        }
        a *= a;
        a %= m;
        b >>= 1;
    }

    return ans;

}

void solve() {

    int n; cin >> n;
    int ans = 1;

    set<int> sb;

    for(int i = 1; i <= n; i++) {
        if(gcd(n, i) == 1) {
            sb.insert(i);
            ans *= i;
            ans %= n;
        }
    }

    if(ans%n == 1) {
        cout << sb.size() << '\n';
        for(int x: sb) cout << x << ' ';
        cout << '\n';
        return;
    }

    int b = binpow(ans, sb.size()-1, n);

    if(sb.count(b)) sb.erase(b);
    else sb.insert(b);

    cout << sb.size() << '\n';

    for(int x: sb) cout << x << ' ';
    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; t = 1;

    while(t--) solve();

    return 0;

}