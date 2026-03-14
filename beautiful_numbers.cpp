#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    string x; cin >> x;
    int n = x.length();

    if(n == 1) return void(cout << 0 << '\n');

    int s = 0;
    for(int j = 0; j < n; j++) s += (x[j]-'0');

    vector<int> a;

    for(int j = 0; j < n; j++) {
        if(j == 0) a.push_back(x[j]-'0'-1);
        else a.push_back(x[j]-'0');
    }

    sort(all(a));

    int ans = 0;

    for(int i = n-1; i >= 0 && s > 9; i--) {
        s -= a[i];
        ans++;
    }

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