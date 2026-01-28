#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    int n, m, sx, sy, d; cin >> n >> m >> sx >> sy >> d;
    int x = 1, y = 1;

    bool ok1 = true, ok2 = true;

    while(x != n || y != m) {
        if(x+1 <= n && abs(sx-x-1)+abs(sy-y) > d) x++;
        else if(y+1 <= m && abs(sx-x)+abs(sy-y-1) > d) y++;
        else { ok1 = false; break; }
    }

    x = 1, y = 1;

    while(x != n || y != m) {
        if(y+1 <= m && abs(sx-x)+abs(sy-y-1) > d) y++;
        else if(x+1 <= n && abs(sx-x-1)+abs(sy-y) > d) x++;
        else { ok2 = false; break; }
    }

    if(ok1 || ok2) cout << abs(n-1)+abs(m-1) << '\n';
    else cout << -1 << '\n';

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}