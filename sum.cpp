#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    vector<int> abc(3);
    cin >> abc[0] >> abc[1] >> abc[2];

    sort(abc.begin(), abc.end());

    if(abc[0]+abc[1] == abc[2]) cout << "YES" << '\n';
    else cout << "NO" << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}