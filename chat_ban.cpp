#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

int cnt(int n, int k) {

    int ans = min(n, k)*(min(n, k)+1)/2;

    if(n > k) {
        int diff = n-k+1;
        ans += (k-1)*k/2-(k-diff)*(k-diff+1)/2;
    }

    return ans;

}

void solve() {

    int k, x; cin >> k >> x;
    int ans = 0;

    int l = 0, r = 2*k-1, mid, t;

    while(l <= r) {
        mid = l+(r-l)/2;
        if(cnt(mid, k) <= x) {
            t = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }
    }

    if(cnt(t, k) < x && t < 2*k-1) t++;

    ans += t;

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