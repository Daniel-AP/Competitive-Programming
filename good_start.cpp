#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

void solve() {

    int w, h, a, b; cin >> w >> h >> a >> b;
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

    int intx = max(min(x1+a, x2+a)-max(x1, x2), 0LL);
    int inty = max(min(y1+b, y2+b)-max(y1, y2), 0LL);

    int dx = abs(min(x1+a, x2+a)-max(x1, x2));
    int dy = abs(min(y1+b, y2+b)-max(y1, y2));

    if(intx != 0) {
        if(dy%b == 0) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    else if(inty != 0) {
        if(dx%a == 0) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    else {
        if(dx%a == 0 || dy%b == 0) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}