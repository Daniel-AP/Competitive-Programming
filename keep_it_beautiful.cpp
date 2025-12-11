#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    int q; cin >> q;

    vector<int> a;
    string ans;

    bool change = false;

    for(int i = 0; i < q; i++) {
        
        int x; cin >> x;

        if(a.size() == 0 || a.back() <= x) {
            if(change && a[0] < x) {
                ans += '0';
            } else {
                ans += '1';
                a.push_back(x);
            }
        } else if(a[0] >= x) {
            if(change) {
                ans += '0';
            } else {
                a.push_back(x);
                change = true;
                ans += '1';
            }
        } else {
            ans += '0';
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