#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;
    string s1, s2; cin >> s1 >> s2;

    if(s2[n-2] == '<') return void(cout << "NO" << '\n');

    for(int i = 0; i < n-1; i++) {
        if(i&1) {
            if(s1[i] == '<' && s2[i+1] == '<') return void(cout << "NO" << '\n');
        } else {
            if(s2[i] == '<' && s1[i+1] == '<') return void(cout << "NO" << '\n');
        }
    }

    cout << "YES" << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}