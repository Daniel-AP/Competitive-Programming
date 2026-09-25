#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> z;
    for(int i = 0; i < n; i++) if(a[i] == 0) z.push_back(i);

    if(z.size() == 1) return void(cout << "NO" << '\n');
    
    cout << "YES" << '\n';
    string ans(n, 'A');

    if(z.empty()) return void(cout << ans << '\n');

    ans[z[0]] = 'C';
    for(int i = 1; i < z.size(); i++) ans[z[i]] = 'B';

    cout << ans << '\n';

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}