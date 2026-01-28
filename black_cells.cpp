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

    if(n == 1) return void(cout << 1 << '\n');
    if(n == 2) return void(cout << a[1]-a[0] << '\n');

    if(n%2 == 0) {

        vector<int> p;

        for(int i = 0; i < n; i += 2) {
            p.push_back(a[i+1]-a[i]);
        }

        sort(p.rbegin(), p.rend());

        cout << p[0] << '\n';
        return;

    }

    int ans = INF;

    for(int i = 0; i < n; i++) {

        int mn = INF, mx = 0;

        for(int j = 0; j < i; j++) {
            if(a[j+1]-a[j] > 1) mn = min(mn, a[i]-(a[j+1]-1));
        }
        for(int j = i; j < n-1; j++) {
            if(a[j+1]-a[j] > 1) mn = min(mn, a[j]+1-a[i]);
        }

        if(a[0] > 0) mn = min(mn, a[i]-(a[0]-1));
        if(a[n-1] < (int)1e18) mn = min(mn, a[n-1]+1-a[i]);

        vector<int> b = a;
        b.erase(b.begin()+i);

        for(int j = 0; j < (int)b.size(); j += 2) {
            mx = max(mx, b[j+1]-b[j]);
        }

        ans = min(ans, max(mx, mn));

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