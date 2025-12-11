#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

void solve() {

    int a, b, c, d; cin >> a >> b >> c >> d;

    if((c <= b && c >= a) || (d >= a && d <= b) || (a <= d && a >= c) || (b >= c && b <= d)) cout << max(b, d)-min(a, c) << '\n';
    else cout << (b-a)+(d-c) << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);

    int t; t = 1;

    while(t--) solve();

    return 0;

}