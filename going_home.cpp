#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    map<int, vector<int>> cnt;
    for(int i = 0; i < n; i++) cnt[a[i]].push_back(i+1);

    vector<int> c;

    for(auto& [k, v]: cnt) {
        if(v.size() >= 2) c.push_back(k);
    }

    if(c.size() == 1) {
        int v = 2*c[0];
        map<int, int> seen;
        for(int i = 0; i < n; i++) {
            if(i+1 == cnt[c[0]][0] || i+1 == cnt[c[0]][1]) continue;
            if(a[i] > v) continue;
            if(seen.find(v-a[i]) != seen.end()) {
                cout << "YES" << '\n';
                cout << cnt[c[0]][0] << ' ' << cnt[c[0]][1] << ' ' << i+1 << ' ' << seen[v-a[i]] << '\n';
                return;
            }
            seen[a[i]] = i+1;
        }
    }

    if(c.size() >= 2) {
        cout << "YES" << '\n';
        cout << cnt[c[0]][0] << ' ' << cnt[c[1]][0] << ' ' << cnt[c[0]][1] << ' ' << cnt[c[1]][1] << '\n';
        return;
    }

    int m = 3200;

    vector<int> ind(n);
    iota(all(ind), 0);
    sort(all(ind), [&](int i, int j) { return a[i] < a[j]; });
    sort(all(a));

    map<int, vector<pair<int, int>>> d;

    for(int i = 0; i < min(n, m); i++) {
        for(int j = i+1; j < min(n, m); j++) {
            if(d.find(a[j]-a[i]) == d.end()) d[a[j]-a[i]].push_back({ i, j });
            if(d[a[j]-a[i]][0].second < i) {
                cout << "YES" << '\n';
                cout << ind[d[a[j]-a[i]][0].first]+1 << ' ' << ind[j]+1 << ' ' << ind[d[a[j]-a[i]][0].second]+1 << ' ' << ind[i]+1 << '\n';
                return;
            }
        }
    }

    cout << "NO" << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}