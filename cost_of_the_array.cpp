#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    int n, k; cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int notone = -1;

    for(int i = 1; i < n; i++) {
        if(a[i] != 1) {
            notone = i;
            break;
        }
    }

    if(notone == -1) {
        cout << 2 << '\n';
        return;
    }

    if(n-notone+1 >= k) {
        cout << 1 << '\n';
        return;
    }

    if(notone >= 4) {
        cout << 2 << '\n';
        return;
    }

    if(k == n) {

        int val = 1;

        for(int i = 1; i < n; i += 2) {
            if(a[i] != val) {
                cout << val << '\n';
                return;
            }
            val++;
        }
        
        cout << k/2+1 << '\n';

        return;
    }

    if(k == n-1) {

        int val = 1;

        for(int i = 1; i < n-1; i += 2) {

            if(a[i] != val) {
                cout << val << '\n';
                return;
            } else if(a[i+1] != val+1) {
                cout << val+1 << '\n';
                return;
            }
            val++;
        }

        cout << k/2+1 << '\n';

        return;

    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}