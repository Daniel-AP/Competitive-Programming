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

    set<int> s(a.begin(), a.end());
    a.assign(s.begin(), s.end());

    int mx = 0;

    for(int i = 0; i < n; i++) {
        int k = upper_bound(a.begin(), a.end(), a[i]+n-1)-a.begin()-1;
        mx = max(mx, k-i+1);
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