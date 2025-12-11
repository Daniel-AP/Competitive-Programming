#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k; cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int l, r, s = (k+1)/2;

    for(int i = 0; i < n; i++) {

        int m = min(a[i], s);

        a[i] -= m;
        s -= m;

    }

    s = k/2;

    for(int i = n-1; i >= 0; i--) {
        int m = min(a[i], s);

        a[i] -= m;
        s -= m;

    }

    cout << count(a.begin(), a.end(), 0) << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}