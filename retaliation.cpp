#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

void solve() {

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int d = a[0]-a[1];
    bool good = true;

    for(int i = 1; i < n-1; i++) {
        if(a[i]-a[i+1] != d) good = false;
    }

    if(!good) {
        cout << "NO" << '\n';
        return;
    }

    for(int i = 0; i < n; i++) {
        if(d < 0) {
            a[i] -= (i+1)*(-d);
        } else {
            a[i] -= (n-i)*d;
        }
    }

    for(int i = 0; i < n; i++) {
        if(a[i]%(n+1) != 0 || a[i] < 0) good = false;
    }

    if(!good) {
        cout << "NO" << '\n';
    } else {
        cout << "YES" << '\n';
    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}