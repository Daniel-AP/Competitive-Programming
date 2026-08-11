#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k; cin >> n >> k;
    int invs = 0, cur = n-1, cnt = 0;

    while(cur > 0 && invs+cur <= k) {
        invs += cur;
        cur--;
        cnt++;
    }

    for(int i = 0; i < cnt; i++) cout << n-i << ' ';
    for(int i = 1; i <= cur-(k-invs); i++) cout << i << ' ';
    cout << n-cnt << ' ';
    for(int i = cur-(k-invs)+1; i < n-cnt; i++) cout << i << ' ';
    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}