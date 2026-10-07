#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

int comb(int n, int k) {

    if(k < 0 || k > n) return 0;
    if(k > n/2) k = n-k;

    int ans = 1;

    for(int i = 1; i <= k; i++) {
        ans *= (n-i+1);
        ans /= i;
    }

    return ans;

}

void solve() {

    int n, k; cin >> n >> k;
    int ans = 0;
    
    for(int i = 1; i < bit_width((unsigned int)n); i++) {
        for(int j = 1; j <= i; j++) {
            if(i-1+j > k) break;
            ans += comb(i-1, j-1);
        }
    }

    for(int i = bit_width((unsigned int)n)-1; i > 0; i--) {
        if((n>>(i-1))&1) {
            for(int j = 1; j < i; j++) {
                ans += comb(i-1, j);
            }
        }
    }

    ans += (bit_width((unsigned int)n)-1+popcount((unsigned int)n) <= k);

    cout << n-ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}