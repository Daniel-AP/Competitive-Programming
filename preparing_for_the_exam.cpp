#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    int n, m, k; cin >> n >> m >> k;

    vector<int> a(m), has(n+1);

    for(int i = 0; i < m; i++) cin >> a[i];

    for(int i = 0; i < k; i++) {
        int q; cin >> q;
        has[q] = 1;
    }

    int cnt = count(has.begin()+1, has.end(), 0);

    if(cnt >= 2) cout << string(m, '0') << '\n';
    else if(cnt == 1) {
        int idx = find(has.begin()+1, has.end(), 0)-has.begin();
        for(int i = 0; i < m; i++) cout << (a[i]==idx ? '1' : '0');
        cout << '\n';
    } else cout << string(m, '1') << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}