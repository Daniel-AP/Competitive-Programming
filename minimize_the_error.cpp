#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k1, k2; cin >> n >> k1 >> k2;

    vector<int> a(n), b(n);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    priority_queue<int> pq;

    for(int i = 0; i < n; i++) {
        pq.push(abs(a[i]-b[i]));
    }

    int k = k1+k2;

    while(k > 0) {
        int err = pq.top(); pq.pop();
        err = abs(err-1);
        pq.push(err);
        k--;
    }

    int ans = 0;

    while(!pq.empty()) {
        ans += pq.top()*pq.top(); pq.pop();
    }

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}