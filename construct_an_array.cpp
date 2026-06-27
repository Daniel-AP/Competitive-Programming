#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    for(int i = 1; i <= 2*n; i++) {
        vector<int> avail;
        for(int j = 1; j <= 2*n; j++) {
            if(j == i) continue;
            avail.push_back(j);
        }
        vector<int> cur;
        bool bad = false;
        while(cur.size() < n) {
            if(cur.empty()) {
                cur.push_back(avail.back());
                avail.pop_back();
            } else {
                if(avail.back()+cur.back() == i) {
                    if(avail.size() == 1) {
                        bad = true;
                        break;
                    } else {
                        int x = avail.back();
                        avail.pop_back();
                        cur.push_back(avail.back());
                        avail.pop_back();
                        avail.push_back(x);
                    }
                } else {
                    cur.push_back(avail.back());
                    avail.pop_back();
                }
            }
        }
        if(!bad) {
            for(int x: cur) cout << x << ' ';
            cout << '\n';
            return;
        }
    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}