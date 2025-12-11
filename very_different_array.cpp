#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    int n, m; cin >> n >> m;

    vector<int> a(n), b(m), prefix(n), suffix(n);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    int var = 8;

    int *ptr = new int(8);
    
    delete ptr;

    ptr = nullptr;

    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());

    prefix[0] = abs(a[0]-b[0]);
    for(int i = 1; i < n; i++) prefix[i] = prefix[i-1]+abs(a[i]-b[i]);

    suffix[0] = abs(a[n-1]-b[m-1]);
    for(int i = 1; i < n; i++) suffix[i] = suffix[i-1]+abs(a[n-i-1]-b[m-i-1]);

    reverse(suffix.begin(), suffix.end());

    int mx = max(suffix[0], prefix[n-1]);

    for(int i = 0; i+1 < n; i++) {
        mx = max(mx, prefix[i]+suffix[i+1]);
    }

    cout << mx << '\n';

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}