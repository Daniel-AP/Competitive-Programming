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

    map<int, int> cnt;
    int ans = 0;

    for(int i = 0; i+4 < n; i++) {
        int s = a[i]+a[i+2]-a[i+4];
        int c = cnt[s];
        c -= (i-4 >= 0 && a[i-4]+a[i-2]-a[i] == s);
        c -= (i-2 >= 0 && a[i-2]+a[i]-a[i+2] == s);
        ans += c;
        cnt[s]++;
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