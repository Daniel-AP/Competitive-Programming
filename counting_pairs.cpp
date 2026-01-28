#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

void solve() {

    int n, x, y; cin >> n >> x >> y;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int s = 0, cnt = 0;
    for(int i = 0; i < n; i++) s += a[i];

    sort(a.begin(), a.end());

    for(int i = 0; i < n; i++) {
        int j = lower_bound(a.begin(), a.end(), s-a[i]-y)-a.begin();
        int k = upper_bound(a.begin(), a.end(), s-a[i]-x)-a.begin()-1;
        cnt += max(k-max(j, i+1)+1, 0LL);
    }

    cout << cnt << "\n";
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}