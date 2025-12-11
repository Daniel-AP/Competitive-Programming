#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int n, g;
    
    while(cin >> n >> g) {

        vector<pair<int, int>> m(n);
        int ans = 0;
    
        for(int i = 0; i < n; i++) {
            int s, r; cin >> s >> r;
            m[i] = { s, r };
            if(s > r) ans += 3;
            if(s == r) ans++;
        }

        sort(m.begin(), m.end(), [&](pair<int, int> a, pair<int, int> b) {
            if(a.first > a.second) return false;
            if(b.first > b.second) return true;
            return abs(a.first-a.second) < abs(b.first-b.second);
        });


        for(int i = 0; i < n; i++) {
            if(m[i].first > m[i].second) continue;
            if(m[i].first < m[i].second && g > 0) {
                if(g == m[i].second-m[i].first) { ans++; g = 0; }
                if(g >= m[i].second-m[i].first+1) { ans += 3; g -= m[i].second-m[i].first+1; }
            }
            if(m[i].first == m[i].second && g > 0) {
                ans += 2; g--;
            }
        }

        cout << ans << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}