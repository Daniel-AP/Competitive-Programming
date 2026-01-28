#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

void solve() {

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    bool good = false;
    int l, r;

    for(int i = 0; i < n; i++) {
        int mx = *max_element(a.begin(), a.begin()+i+1);
        int mn = *min_element(a.begin()+i, a.end());
        if(mx > mn) {
            good = true;
            l = mx, r = mn;
            break;
        }
    }

    if(good) {
        cout << "YES" << '\n';
        cout << 2 << '\n';
        cout << l << ' ' << r << '\n';
    } else {
        cout << "NO" << '\n';
    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}