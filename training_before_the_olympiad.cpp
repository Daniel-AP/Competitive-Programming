#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int s = 0, cnt = 0;

    for(int i = 0; i < n; i++) {
        cnt += a[i]%2;
        s += a[i];
        if(cnt%3 == 0 || cnt%3 == 2) cout << s-cnt/3 << ' ';
        else if(i > 0) cout << s-cnt/3-1 << ' ';
        else cout << s << ' ';
    }

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