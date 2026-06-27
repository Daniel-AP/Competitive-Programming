#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

int first(int i) {
    return i*(i+1)/2-i+1;
}

int sum(int i, int j) {
    i--;
    return j*(j+1)*(2*j+1)/6 - i*(i+1)*(2*i+1)/6;
}

int rngsum(int i, int j, int k) {
    int f = first(k);
    return sum(f+i-1, f+j-1);
}

void solve() {

    int n; cin >> n;
    int l = 1, r = 2023, mid, k;

    while(l <= r) {
        mid = l+(r-l)/2;
        if(first(mid) <= n) k = mid, l = mid+1;
        else r = mid-1;
    }

    int lr = n-first(k)+1, rr = lr;
    int ans = 0;

    while(k > 0) {
        ans += rngsum(lr, rr, k);
        k--;
        lr--;
        lr = max(lr, 1LL);
        rr = min(rr, k);
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