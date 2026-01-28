#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    int n, m, k; cin >> n >> m >> k;
    string s; cin >> s;

    int i = 0, cnt = 0, ans = 0;

    while(i < n) {
        if(s[i] == '0') {
            cnt++;
            if(cnt == m) {
                i += k;
                ans++;
                cnt = 0;
            } else {
                i++;
            }
        } else {
            cnt = 0;
            i++;
        }
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