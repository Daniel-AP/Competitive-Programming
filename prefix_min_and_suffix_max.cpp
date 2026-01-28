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

    cout << 1;

    vector<int> mn(n), mx(n);

    mn[0] = a[0]; mx[n-1] = a[n-1];

    for(int i = 1; i < n; i++) {
        mn[i] = min(mn[i-1], a[i]);
    }

    for(int i = n-2; i >= 0; i--) {
        mx[i] = max(mx[i+1], a[i]);
    }

    for(int i = 1; i < n-1; i++) {
        if((a[i] < mn[i-1] && a[i] < mx[i+1]) || (a[i] > mn[i-1] && a[i] > mx[i+1])) {
            cout << 1;
        }
        else if(a[i] == mn[i] || a[i] == mx[i]) {
            cout << 1;
        }
        else cout << 0;
    }

    cout << 1;
    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}