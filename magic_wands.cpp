#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k; cin >> n >> k;
    string s; cin >> s;

    vector<int> rng(n+1);

    int ans = 0, cnt = 0;

    for(int i = 0; i < n; i++) {
        cnt += rng[i];
        if((s[i] == 'S')^(cnt&1)) {
            if(i+k > n) return void(cout << -1 << '\n');
            rng[i]++;
            rng[i+k]--;
            cnt++;
            ans++;
        }
    }

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}