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

    sort(a.begin(), a.end());

    int f1 = INF, l1 = 0, f2 = INF, l2 = 0;

    for(int i = 0; i < n; i++) {
        if(a[i]%2 == 0) { f1 = min(f1, i); l1 = i; }
        if(a[i]%2 == 1) { f2 = min(f2, i); l2 = i; }
    }

    int mn = *min_element(a.begin(), a.end())%2;
    int mx = *max_element(a.begin(), a.end())%2;

    if(mn == mx) {
        cout << 0 << "\n";
    } else if(mn == 1 && mx == 0) {
        cout << min({ f1, n-1-l2 }) << "\n";
    } else {
        cout << min({ f2, n-1-l1 }) << "\n";
    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}