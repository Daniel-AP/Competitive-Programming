#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k; cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    int l = 1, r = 1e10, mid, ans;

    while(l <= r) {

        mid = l+(r-l)/2;

        int tops = 0, tans = 0;

        for(int i = 0; i < n; i++) {

            tops += min({mid, a[i], k-tans});
            tans += min({mid, a[i], k-tans});

            if(a[i] < mid) tops++;

        }

        if(tans >= k) {
            ans = tops;
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

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}