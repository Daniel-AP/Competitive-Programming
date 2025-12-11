#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

void solve() {

    int W, H; cin >> W >> H;
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    int w, h; cin >> w >> h;

    int ans = INF;
    int dx, dy;

    dx = max(w-x1, 0LL);
    dy = max(h-y1, 0LL);

    if(W-x2 >= dx && H-y2 >= dy) ans = min({ ans, dx, dy });
    else if(W-x2 >= dx) ans = min(ans, dx);
    else if(H-y2 >= dy) ans = min(ans, dy);

    dx = max(x2-(W-w), 0LL);
    dy = max(h-y1, 0LL);

    if(x1 >= dx && H-y2 >= dy) ans = min({ ans, dx, dy });
    else if(x1 >= dx) ans = min(ans, dx);
    else if(H-y2 >= dy) ans = min(ans, dy);

    dx = max(w-x1, 0LL);
    dy = max(y2-(H-h), 0LL);

    if(W-x2 >= dx && y1 >= dy) ans = min({ ans, dx, dy });
    else if(W-x2 >= dx) ans = min(ans, dx);
    else if(y1 >= dy) ans = min(ans, dy);

    dx = max(x2-(W-w), 0LL);
    dy = max(y2-(H-h), 0LL);

    if(x1 >= dx && y1 >= dy) ans = min({ ans, dx, dy });
    else if(x1 >= dx) ans = min(ans, dx);
    else if(y1 >= dy) ans = min(ans, dy);

    if(ans == INF) cout << -1 << '\n';
    else cout << setprecision(7) << fixed << double(ans) << '\n';

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}