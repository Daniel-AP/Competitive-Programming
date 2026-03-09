#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<pair<int, int>> lr(n);

    for(int i = 0; i < n; i++) {
        cin >> lr[i].first >> lr[i].second;
    }

    map<int, int> diff;

    for(int i = 0; i < n; i++) {
        diff[lr[i].first]++;
        diff[lr[i].second+1]--;
    }

    int cur = 0;

    for(auto& [k, v]: diff) {
        cur += v;
        if(cur > 2) return void(cout << "NO" << '\n');
    }

    cout << "YES" << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}