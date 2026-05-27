#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> c(n);
    for(int i = 0; i < n; i++) cin >> c[i];

    int ans1 = 0, ans2 = 0;
    int cnt1 = count(all(c), 1);

    ans1 = c.back()+min(c.back()/2, cnt1);
    
    int s = 0;
    for(int i = n-1; i >= 0 && c[i] > 1; i--) {
        ans2 += c[i];
        s += (c[i]-2)/2;
    }

    ans2 += min(s, cnt1);

    if(max(ans1, ans2) < 3) cout << 0 << '\n';
    else cout << max(ans1, ans2) << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}