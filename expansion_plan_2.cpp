#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, x, y; cin >> n >> x >> y;
    string s; cin >> s;

    x = abs(x), y = abs(y);

    vector<int> row(n+5);

    int cnt4 = count(s.begin(), s.end(), '4');
    int cnt8 = count(s.begin(), s.end(), '8');

    for(int i = 0; i <= cnt8; i++) {
        row[i] = cnt8+1;
    }

    int cur = cnt8+1;

    for(int i = cnt8+cnt4; i >= 0; i--, cur++) {
        row[i] = min(cur, cnt4+cnt8+1);
    }

    if(y >= n+5) return void(cout << "NO" << '\n');

    cout << (row[y] > x ? "YES" : "NO") << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}