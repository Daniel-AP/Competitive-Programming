#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    int n; cin >> n;
    string s; cin >> s;

    int ans = 0;

    for(int i = 0; i+4 < n; i++) {
        if(s.substr(i, 5) == "mapie") {
            ans++;
            s[i+2] = '#';
        }
    }

    for(int i = 0; i+2 < n; i++) {
        if(s.substr(i, 3) == "map") {
            ans++;
            s[i] = '#';
        }
    }

    for(int i = 0; i+2 < n; i++) {
        if(s.substr(i, 3) == "pie") {
            ans++;
            s[i] = '#';
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