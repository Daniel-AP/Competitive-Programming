#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int l = 0, r = INF, x, ans = -1;

    while(l <= r) {

        x = l+(r-l)/2;

        auto it = max_element(a.begin(), a.end());
        *it += x;

        double s = 0;

        for(int i = 0; i < n; i++) s += a[i];
        s /= n;

        int cnt = 0;

        for(int i = 0; i < n; i++) {
            if(a[i] >= s/2) continue;
            cnt++;
        }

        *it -= x;

        if(cnt >= n/2+1) {
            ans = x;
            r = x-1;
        } else {
            l = x+1;
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