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

    bool same = true;

    for(int i = 1; i < n; i++) {
        if(a[i-1] != a[i]) same = false;
    }

    if(same) {
        cout << 1 << '\n';
        return;
    }
    
    int l = 2, r = n, mid, ans;

    while(l <= r) {

        mid = l+(r-l)/2;

        vector<int> d(20), m(20);
        bool good = true;
        
        for(int i = 0; i < mid; i++) {
            for(int j = 0; j < 20; j++) {
                if(a[i]&(1<<j)) d[j]++;
            }
        }

        for(int i = 0; i < 20; i++) m[i] = d[i];
        
        for(int i = mid; i < n; i++) {
            for(int j = 0; j < 20; j++) {
                if(a[i]&(1<<j)) m[j]++;
            }
            for(int j = 0; j < 20; j++) {
                if(a[i-mid]&(1<<j)) m[j]--;
            }
            for(int j = 0; j < 20; j++) {
                if((d[j]==0) != (m[j]==0)) good = false;
            }
        }

        if(good) {
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }

    }

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}