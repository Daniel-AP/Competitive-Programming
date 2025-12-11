#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    if(popcount(n)&1) return void(cout << "NO" << '\n');

    bool o = 0;
    int k = bit_width(n);

    string s1 = "", s2 = "";

    for(int i = 0; i < k; i++) {
        if((n&(1LL<<i)) != 0) o = true, s1 += "1";
        if((n&(1LL<<i)) == 0 && o) s1 += "0";
    }

    s2 = s1;

    reverse(s2.begin(), s2.end());

    if(s1 == s2) cout << "YES" << '\n';
    else cout << "NO" << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}