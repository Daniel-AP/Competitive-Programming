#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, m, d; cin >> n >> m >> d;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int s = 0, ans = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 0; i < n; i++) {
        if(a[i] > 0) {
            pq.push(a[i]);
            s += a[i];
        }
        if(pq.size() > m) {
            int mn = pq.top(); pq.pop();
            s -= mn;
        }
        ans = max(ans, s-d*(i+1));
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