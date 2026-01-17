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

    vector<int> cnt(n+1);
    for(int i = 0; i < n; i++) cnt[a[i]]++;

    sort(all(cnt));

    for(int i = n-1; i >= 1; i--) {
        cnt[i] = min(cnt[i], cnt[i+1]-1);
    }

    int ans = 0;
    for(int i = 0; i <= n; i++) ans += max(cnt[i], 0LL);

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