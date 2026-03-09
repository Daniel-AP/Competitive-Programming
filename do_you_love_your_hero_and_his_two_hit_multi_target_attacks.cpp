#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int k; cin >> k;
    int start = 0, step = 1000;

    int cnt = 0;

    vector<pair<int, int>> staff;

    while(k) {
        int x = 2;
        staff.push_back({ start, start });
        for(; x*(x-1)/2 <= k; x++) staff.push_back({ start+step*(x-1), start });
        x--;
        start++;
        cnt += x;
        k -= x*(x-1)/2;
    }

    cout << cnt << '\n';
    for(auto& [x, y]: staff) cout << x << ' ' << y << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}