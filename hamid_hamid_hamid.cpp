#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, x; cin >> n >> x;
    string s; cin >> s;

    int i1 = -1, i2 = -1;

    for(int i = 0; i < x; i++) if(s[i] == '#') i1 = i;
    for(int i = x; i < n; i++) if(s[i] == '#') { i2 = i; break; }

    if(i1 == -1 && i2 == -1) {
        cout << 1 << '\n';
    } else if(i1 != -1 && i2 == -1) {
        cout << min(i1+2, n-x+1) << '\n';
    } else if(i1 == -1 && i2 != -1) {
        cout << min(x, n-i2+1) << '\n';
    } else {
        if(i1+2 < n-i2+1) {
            cout << min(x, n-i2+1) << '\n';
        } else {
            cout << min(i1+2, n-x+1) << '\n';
        }
    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}