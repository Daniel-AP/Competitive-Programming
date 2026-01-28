#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    int n; cin >> n;
    string s1, s2; cin >> s1 >> s2;

    int ans = 0;

    for(int i = 1; i+1 < n; i++) {
        if(s1.substr(i-1, 3) == "x.x" && s2.substr(i-1, 3) == "...") ans++;
        if(s2.substr(i-1, 3) == "x.x" && s1.substr(i-1, 3) == "...") ans++;
    }

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}