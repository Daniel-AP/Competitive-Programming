#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, m; cin >> n >> m;
    string s; cin >> s;

    set<int> b;
    
    for(int i = 0; i < m; i++) {
        int x; cin >> x;
        b.insert(x);
    }

    int last = 0, cnta = 0;
    bool change = true, hasB = false;

    if(s[0] == 'A') {
        change = (b.find(2) == b.end());
        b.insert(2);
        last = 2;
    } else {
        for(int i = 2; i <= 1e9; i++) {
            if(b.find(i) == b.end()) {
                b.insert(i);
                last = i;
                break;
            }
        }
        hasB = true;
    }

    // cout << "last: " << last << '\n';
    // cout << "has 1: " << (b.find(1) != b.end()) << '\n';

    for(int i = 1; i < n; i++) {
        if(change) {

            int nxLast = last;

            if(hasB) {

                int k = last-cnta;

                for(int j = k; j <= 1e9; j++) {
                    if(b.find(j) == b.end()) {
                        nxLast = j+cnta;
                        break;
                    }
                }

            }

            if(s[i] == 'A') {
                nxLast++;
                if(hasB) cnta++;
            } else {
                for(int j = nxLast+1; j <= 1e9; j++) {
                    if(b.find(j) == b.end()) {
                        nxLast = j;
                        break;
                    }
                }
                cnta = 0;
                hasB = true;
            }

            change = (b.find(nxLast) == b.end());
            b.insert(nxLast);
            last = nxLast;

        } else {

            int nxLast = last;

            if(s[i] == 'A') {
                nxLast++;
                if(hasB) cnta++;
            } else {
                for(int j = nxLast+1; j <= 1e9; j++) {
                    if(b.find(j) == b.end()) {
                        nxLast = j;
                        break;
                    }
                }
                cnta = 0;
                hasB = true;
            }

            change = (b.find(nxLast) == b.end());
            b.insert(nxLast);
            last = nxLast;

        }
    }

    cout << b.size() << '\n';
    for(int x: b) cout << x << ' ';
    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}