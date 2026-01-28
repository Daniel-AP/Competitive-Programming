#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

void solve() {

    int n, m; cin >> n >> m;
    int acc = 0;

    vector<int> r1(100), r2(100);
    
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        for(int j = 0; j < a; j++) r1[acc+j] = b;
        acc += a;
    }

    acc = 0;

    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        for(int j = 0; j < a; j++) r2[acc+j] = b;
        acc += a;
    }

    int mx = 0;

    for(int i = 0; i < 100; i++) {
        mx = max(r2[i]-r1[i], mx);
    }

    cout << mx;
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);

    int t; t = 1;

    while(t--) solve();

    return 0;

}