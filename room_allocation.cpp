#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;

    vector<int> ind(n);
    iota(all(ind), 0);
    sort(all(ind), [&](int i, int j) { return a[i] < a[j]; });

    int l = 1, r = n, mid, ans;

    while(l <= r) {

        mid = l+(r-l)/2;
        bool good = true;

        stack<int> free;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> occ;

        for(int i = 0; i < mid; i++) free.push(i);

        for(int i: ind) {
            while(!occ.empty() && occ.top().first < a[i].first) {
                free.push(occ.top().second);
                occ.pop();
            }
            if(free.empty()) { good = false; break; }
            int r = free.top(); free.pop();
            occ.push({ a[i].second, r });
        }

        if(good) {
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }

    }

    cout << ans << '\n';

    stack<int> free;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> occ;
    vector<int> room(n);

    for(int i = 0; i < ans; i++) free.push(i);
    
    for(int i: ind) {
        while(!occ.empty() && occ.top().first < a[i].first) {
            free.push(occ.top().second);
            occ.pop();
        }
        int r = free.top(); free.pop();
        occ.push({ a[i].second, r });
        room[i] = r;
    }

    for(int r: room) cout << r+1 << ' ';
    cout << '\n';

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}