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

    vector<int> p(n);
    for(int i = 0; i < n; i++) cin >> p[i];

    set<int> s;
    
    for(int i = 1; i <= n; i++) s.insert(i);
    for(int i = 0; i < n; i++) s.erase(p[i]);

    int l = -1, r = -1;

    for(int i = 0; i < n; i++) {
        if(p[i] != i+1) {
            l = i;
            break;
        }
    }

    for(int i = n-1; i >= 0; i--) {
        if(p[i] != i+1) {
            r = i;
            break;
        }
    }

    int cnt = count(p.begin(), p.end(), 0);

    if(cnt == 0) {
        if(l == r) cout << 0 << '\n';
        else cout << r-l+1 << '\n';
        return;
    }

    if(cnt == 1) {

        if(l == r) return void(cout << 0 << '\n');

        if(p[l] == 0) p[l] = *s.begin();
        if(p[r] == 0) p[r] = *s.begin();

        l = -1, r = -1;

        for(int i = 0; i < n; i++) {
            if(p[i] != i+1) {
                l = i;
                break;
            }
        }

        for(int i = n-1; i >= 0; i--) {
            if(p[i] != i+1) {
                r = i;
                break;
            }
        }

        if(l == r) cout << 0 << '\n';
        else cout << r-l+1 << '\n';

    } else {
        cout << r-l+1 << '\n';
    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}