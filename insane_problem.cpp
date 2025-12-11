#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    int k, l1, r1, l2, r2; cin >> k >> l1 >> r1 >> l2 >> r2;
    int ans = 0;

    for(int i = 1; i <= r2; i *= k) {

        int l = l1, r = r1, mid, start = INF;

        while(l <= r) {

            mid = l+(r-l)/2;

            if(i*mid >= l2) {
                start = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }

        }

        if(start == INF || i*start > r2) continue;

        l = start, r = r1;
        int end = -1;

        while(l <= r) {

            mid = l+(r-l)/2;

            if(i*mid <= r2) {
                end = mid;
                l = mid+1;
            } else {
                r = mid-1;
            }

        }

        ans += end-start+1;
        
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