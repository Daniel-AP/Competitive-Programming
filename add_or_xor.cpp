#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

void solve() {

    int a, b, x, y; cin >> a >> b >> x >> y;
    int cnt = 0;

    if(a == b) {
        cout << 0 << '\n';
        return;
    }

    if(a > b) {
        if((a^1) == b) cout << y << '\n';
        else cout << -1 << '\n';
        return;
    }

    while(a != b) {
        if(a%2 == 0) cnt += min(x, y);
        else cnt += x;
        a++;
    }

    cout << cnt << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}