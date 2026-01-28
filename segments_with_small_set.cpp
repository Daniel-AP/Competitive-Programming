#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k; cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int l = 0, cur = 0, ans = 0;
    vector<int> has(100005);

    for(int r = 0; r < n; r++) {
        has[a[r]]++;
        cur += (has[a[r]]==1);
        while(cur > k) {
            has[a[l]]--;
            cur -= (has[a[l]]==0);
            l++;
        }
        ans += r-l+1;
    }

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}