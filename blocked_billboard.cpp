#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

void solve() {

    vector<int> a(4), b(4), c(4);

    for(int i = 0; i < 4; i++) cin >> a[i];
    for(int i = 0; i < 4; i++) cin >> b[i];
    for(int i = 0; i < 4; i++) cin >> c[i];

    int dx1 = max((min(a[2], c[2]))-(max(a[0], c[0])), 0LL);
    int dy1 = max((min(a[3], c[3]))-(max(a[1], c[1])), 0LL);
    int dx2 = max((min(b[2], c[2]))-(max(b[0], c[0])), 0LL);
    int dy2 = max((min(b[3], c[3]))-(max(b[1], c[1])), 0LL);

    cout << (((a[0])-(a[2]))*((a[1])-(a[3]))-dx1*dy1)+(((b[0])-(b[2]))*((b[1])-(b[3]))-dx2*dy2);
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);

    int t; t = 1;

    while(t--) solve();

    return 0;

}