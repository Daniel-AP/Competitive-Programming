#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

void solve() {

    int n; cin >> n;

    vector<int> a(n), mn(n), b;
    for(int i = 0; i < n; i++) cin >> a[i];
    
    b = a;

    mn[0] = a[0];
    for(int i = 1; i < n; i++) mn[i] = min(mn[i-1], a[i]);

    int s = 0, k = 0, m = INF;

    for(int i = 0; i < n; i++) s += mn[i];

    b[0] = b[0]+b[1];
    b[1] = 0;

    mn[0] = b[0];
    for(int i = 1; i < n; i++) mn[i] = min(mn[i-1], b[i]);
    b = a;
    for(int i = 0; i < n; i++) k += mn[i];

    if(n >= 3) {
        m = 0;
        b[1] = b[1]+b[2];
        b[2] = 0;
        mn[0] = b[0];
        for(int i = 1; i < n; i++) mn[i] = min(mn[i-1], b[i]);
        for(int i = 0; i < n; i++) {
            m += mn[i];
        }
    }

    // cout << m << '\n';
    cout << min({ k, s, m }) << '\n';

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}