#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i  < n; i++) cin >> a[i];

    int q; cin >> q;

    vector<vector<int>> b(n+1, vector<int>(32));

    for(int i = 1; i <= n; i++) {
        b[i] = b[i-1];
        for(int j = 0; j < 32; j++) if(a[i-1]&(1LL<<j)) b[i][j]++;
    }

    while(q--) {

        int l, k; cin >> l >> k;
        int lb = l, rb = n, mid, ans = -1;

        while(lb <= rb) {

            mid = lb+(rb-lb)/2;
            int res = 0;

            for(int i = 0; i < 32; i++) {
                if(b[mid][i]-b[l-1][i] == mid-l+1) res |= (1LL<<i);
            }

            if(res >= k) {
                ans = mid;
                lb = mid+1;
            } else {
                rb = mid-1;
            }

        }

        cout << ans << ' ';
        
    }
    
    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}