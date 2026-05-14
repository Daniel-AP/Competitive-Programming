#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, m; cin >> n >> m;
    int ans = 0;

    priority_queue<int> pq1, pq2;

    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        ans += x;
        if(i%2) pq1.push(x);
        else pq2.push(x);
    }

    bool has1 = false, has2 = false;

    for(int i = 0; i < m; i++) {
        int x; cin >> x;
        if(x%2) {
            if(!pq1.empty()) {
                if(!has1 || pq1.top() > 0) {
                    ans -= pq1.top();
                    pq1.pop();
                    has1 = true;
                }
            }
        } else {
            if(!pq2.empty()) {
                if(!has2 || pq2.top() > 0) {
                    ans -= pq2.top();
                    pq2.pop();
                    has2 = true;
                }
            }
        }
    }

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}