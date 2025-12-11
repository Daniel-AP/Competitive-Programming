#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

void solve() {

    int k; cin >> k;

    int l(1), r(INF), mid, ans;

    while(l <= r) {

        mid = l+(r-l)/2;
        int s = sqrtl(mid);

        if(mid-s == k) {
            ans = mid;
            r = mid-1;
        } else if(mid-s > k) {
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