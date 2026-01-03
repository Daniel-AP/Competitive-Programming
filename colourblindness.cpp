#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;
    string s1, s2; cin >> s1 >> s2;

    vector<int> v1, v2;

    for(int i = 0; i < n; i++) {
        if(s1[i] == 'R') v1.push_back(i);
    }
    for(int i = 0; i < n; i++) {
        if(s2[i] == 'R') v2.push_back(i);
    }

    if(v1 == v2) cout << "YES" << '\n';
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