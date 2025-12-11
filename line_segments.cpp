#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

void solve() {

    int n; cin >> n;
    int px, py, qx, qy; cin >> px >> py >> qx >> qy;

    double s = 0, mx = 0;

    for(int i = 0; i < n; i++) {
        double a; cin >> a;
        s += a;
        mx = max(mx, a);
    }

    int dx = qx-px;
    int dy = qy-py;
    double d = sqrtl(dx*dx+dy*dy);

    mx = max(mx, d);
    
    if((d+s)-mx >= mx) cout << "YES" << '\n';
    else cout << "NO" << '\n';

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}