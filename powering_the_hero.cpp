#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];

    priority_queue<int> pq;

    int ans = 0;

    for(int i = 0; i < n; i++) {
        if(s[i] == 0 && !pq.empty()) {
            ans += pq.top(); pq.pop();
        } else {
            pq.push(s[i]);
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