#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    int n; cin >> n;
    string s; cin >> s;

    int cnt = 0, ans = 0, mx = 0;

    for(int i = 0; i < n; i++) {
        if(s[i] == '.') cnt++, ans++;
        else if(cnt) {
            mx = max(mx, cnt);
            cnt = 0;
        }
    }
    
    mx = max(mx, cnt);

    if(mx > 2) cout << min(ans, 2LL) << '\n';
    else cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}