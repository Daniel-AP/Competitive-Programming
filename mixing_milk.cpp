#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

void solve() {

    vector<int> c(3), m(3);

    for(int i = 0; i < 3; i++) {
        cin >> c[i] >> m[i];
    }

    for(int i = 0; i < 100; i++) {
        int k = min(m[i%3], c[(i+1)%3]-m[(i+1)%3]);
        m[i%3] -= k; m[(i+1)%3] += k;
    }
    
    for(int i = 0; i < 3; i++) cout << m[i] << '\n';

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);

    int t; t = 1;

    while(t--) solve();

    return 0;

}