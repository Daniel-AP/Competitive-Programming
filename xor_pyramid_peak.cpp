#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n), cnt(n+1);

    for(int i = 0; i < n; i++) cin >> a[i];

    cnt[1] = 0;
    
    for(int i = 2; i <= n; i++) {
        cnt[i] = cnt[i-1];
        int m = i;
        while(m%2 == 0) cnt[i]++, m /= 2;
    }

    int ans = 0;

    for(int i = 0; i < n; i++) {
        if(cnt[n-1]-cnt[i]-cnt[n-1-i] == 0) ans ^= a[i];
    }

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}