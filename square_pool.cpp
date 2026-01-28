#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    int n, s; cin >> n >> s;

    int ans = 0;

    for(int i = 0; i < n; i++) {

        int dx, dy, xi, yi; cin >> dx >> dy >> xi >> yi;

        if(xi+yi == s && dx+dy == 0) ans++;
        else if(xi == yi && abs(dx+dy) == 2) ans++;

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