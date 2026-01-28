#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;
    string s; cin >> s;

    vector<int> p(n);
    iota(p.begin(), p.end(), 1);

    int l = 0;

    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            reverse(p.begin()+l, p.begin()+i);
            l = i+1;
        }
    }

    reverse(p.begin()+l, p.end());

    vector<int> mn(n), mx(n);
    mn[n-1] = INF, mx[0] = 0;

    for(int i = n-2; i >= 0; i--) {
        mn[i] = min(mn[i+1], p[i+1]);
    }

    for(int i = 1; i < n; i++) {
        mx[i] = max(mx[i-1], p[i-1]);
    }

    bool good = true;

    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            if(mn[i] < p[i] || mx[i] > p[i]) {
                good = false;
                // cout << "WRONG";
            }
        } else {
            if(i == 0) {
                if(mn[i] > p[i]) {
                    good = false;
                    // cout << "8888" << '\n';
                }
            } else if(i == n-1) {
                if(mx[i] < p[i]) {
                    good = false;
                    // cout << "pppp" << '\n';
                }
            } else if(mn[i] > p[i] && mx[i] < p[i]) {
                good = false;
                // cout << "WRONG";
            }
        }
    }

    if(!good) return void(cout << "NO" << '\n');

    cout << "YES" << '\n';

    for(int x: p) cout << x << ' ';
    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}