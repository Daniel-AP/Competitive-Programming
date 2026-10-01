#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;
    map<int, int> cnt;

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        cnt[x]++;
    }

    vector<int> cur, ans;

    while(true) {
        cur.clear();
        bool cont = false;
        for(auto [k, v]: cnt) {
            if(v > 0) cont = true;
            else continue;
            cur.push_back(k);
            cnt[k]--;
        }
        if(!cont) break;
        reverse(all(cur));
        for(int x: cur) ans.push_back(x);
    }

    for(int x: ans) cout << x << ' ';
    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}