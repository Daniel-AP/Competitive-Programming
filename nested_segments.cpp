#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<array<int, 3>> segs(n);

    for(int i = 0; i < n; i++) {
        cin >> segs[i][0] >> segs[i][1];
        segs[i][2] = i+1;
    }

    sort(all(segs), [&](array<int, 3>& p1, array<int, 3>& p2) {
        if(p1[0] != p2[0]) return p1[0] < p2[0];
        else return p1[1] > p2[1];
    });

    priority_queue<pair<int, int>> pq;

    for(int i = 0; i < n; i++) {
        if(!pq.empty()) {
            auto [mx, j] = pq.top();
            if(mx >= segs[i][1]) {
                cout << segs[i][2] << ' ' << segs[j][2] << '\n';
                return;
            }
        }
        pq.push({ segs[i][1], i });
    }

    cout << -1 << ' ' << -1 << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}