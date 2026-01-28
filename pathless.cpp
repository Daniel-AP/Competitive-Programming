#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    int n, s; cin >> n >> s;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int sm = 0;
    for(int i = 0; i < n; i++) sm += a[i];

    vector<int> ind = { 0, 2, 1 };

    if(s < sm) {
        sort(a.rbegin(), a.rend());
        for(int x: a) cout << x << ' ';
        cout << '\n';
    } else if(s == sm) {
        cout << -1 << '\n';
    } else {

        sort(a.begin(), a.end(), [&](int x, int y) {
            return ind[x] > ind[y];
        });
        
        if(sm+1 == s) {
            for(int x: a) cout << x << ' ';
            cout << '\n';
        } else {
            cout << -1 << '\n';
        }

    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}