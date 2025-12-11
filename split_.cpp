#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> cnt(2*n+1);
    for(int i = 0; i < 2*n; i++) {
        int x; cin >> x;
        cnt[x]++;
    }

    int even = 0, ans = 0, o = false, e = false;

    for(int i = 1; i <= 2*n; i++) {
        if(cnt[i] == 0) continue;
        if(cnt[i]&1) ans++, o = true;
        else {
            if(cnt[i]%4 == 0) even++;
            else ans += 2, e = true;
        }
    }

    ans += (even/2)*4;
    even %= 2;
    
    if(o) ans += even*2;

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