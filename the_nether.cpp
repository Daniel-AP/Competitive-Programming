#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    int n; cin >> n;

    map<int, vector<int>> mp;

    for(int i = 1; i <= n; i++) {
        cout << '?' << ' ' << i << ' ' << n << ' ';
        for(int j = 1; j <= n; j++) cout << j << ' ';
        cout << endl;
        int k; cin >> k;
        mp[k].push_back(i);
    }

    auto it = prev(mp.end());

    int k = it->first;
    int prev = mp[k][0];

    vector<int> ans;
    ans.push_back(prev);

    for(int i = k-1; i >= 0; i--) {
        for(int p: mp[i]) {
            cout << '?' << ' ' << prev << ' ' << 2 << ' ' << prev << ' ' << p << endl;
            int q; cin >> q;
            if(q == 2) {
                ans.push_back(p);
                prev = p;
                break;
            }
        }
    }

    cout << '!' << ' ' << k << ' ';
    for(int x: ans) cout << x << ' ';
    cout << endl;
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}